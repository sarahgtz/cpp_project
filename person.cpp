#include "person.h"

Person::Person (shared_ptr<Id> ownId, shared_ptr<Id> fatherId, shared_ptr<Id> motherId):
        ownId(ownId), fatherId(fatherId), motherId(motherId), mark(0) {}

shared_ptr<Person> Person::readPerson(istream &s) {
    string firstname, lastname, gender, fatherFirstname, fatherLastname, motherFirstname, motherLastname;
    unsigned birthyear, deathyear, fatherBirthyear, motherBirthyear;

    s >> firstname >> lastname >> gender >> birthyear >> deathyear
      >> fatherFirstname >> fatherLastname >> fatherBirthyear
      >> motherFirstname >> motherLastname >> motherBirthyear;
    if(!s) throw EOFException();

    auto ownId = make_shared<Id>(firstname, lastname, birthyear);
    auto fatherId = make_shared<Id>(fatherFirstname, fatherLastname, fatherBirthyear);
    auto motherId = make_shared<Id>(motherFirstname, motherLastname, motherBirthyear);
    return make_shared<Person>(ownId, fatherId, motherId);
}

void Person::print(ostream &o) const {
    o << *ownId;
}