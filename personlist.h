#ifndef PERSONLIST_H
#define PERSONLIST_H

#include "person.h"
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>

using namespace std;

/** A list of people */
class PersonList {
public:
    PersonList(const char *fileName);
    PersonList() = default;

    const vector<shared_ptr<Person>> &getPList() const { return pList; }

    shared_ptr<Person> findPerson(const Id &id) const;
    void print(ostream &o = cout) const;

private:
    vector<shared_ptr<Person>> pList;

protected:
    void addPerson(const shared_ptr<Person> &p) { pList.push_back(p); }
};

inline ostream &operator<<(ostream &o, const PersonList &pl) {
    pl.print(o);
    return o;
}

#endif
