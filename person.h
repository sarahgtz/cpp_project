#ifndef PERSON_H
#define PERSON_H
#include <memory>
#include "id.h"

using namespace std;

class EOFException {};

/** A person contains their own ID, their father's ID and their mother's ID*/
class Person {
public:
    Person (shared_ptr<Id> ownId, shared_ptr<Id> fatherId, shared_ptr<Id> motherId);

    shared_ptr<Id> getOwnId() const { return ownId; }
    shared_ptr<Id> getFatherId() const { return fatherId; }
    shared_ptr<Id> getMotherId() const { return motherId; }

    void markAs(unsigned updatedMark) { mark = updatedMark; }
    unsigned getMark() const { return mark; }

    static shared_ptr<Person> readPerson(istream &s);
    void print(ostream &o = cout) const;

private:
    shared_ptr<Id> ownId, fatherId, motherId;
    unsigned mark; // 0 = unmarked, 1=ancestor, 2=descendant
};

inline ostream &operator<< (ostream &o, const Person &p) {
    p.print(o);
    return o;
}

#endif
