#include "personlist.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <set>

PersonList::PersonList(const char *fileName) {
	ifstream s(fileName);
    if (!s.is_open()) {
        cerr << "Error: Could not open file " << fileName << endl;
        exit(1);
    }
    try {
        for (;;) { pList.push_back(Person::readPerson(s)); }
    } catch (EOFException) {}
}

shared_ptr<Person> PersonList::findPerson(const Id &id) const {
    for (const auto &person : pList) {
        if (*person->getOwnId() == id) { return person; }
    }
    cerr << "Person named " << id.getFirstname() << " " << id.getLastname() << ", born " << id.getBirthyear() << " not found" << endl;
    exit(1);
}

struct PersonOrder {
	bool operator() (const shared_ptr<Person> &a, const shared_ptr<Person> &b) const {
    	return *a->getOwnId() < *b->getOwnId();
    }
};

void PersonList::print(ostream &o) const {
	set<shared_ptr<Person>, PersonOrder> ps;
    for (const auto &person : pList) ps.insert(person);

    for (const auto &person : ps) {
        o << *person << endl;
    }
}

