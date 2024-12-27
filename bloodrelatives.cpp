#include "bloodrelatives.h"
#include <algorithm>

using namespace std;

void markAncestors(const PersonList &pList, const shared_ptr<Person> &person) {
    if (person == nullptr || person->getMark() == 1) return;
    person->markAs(1);

    for (const auto &current : pList.getPList()) {
        if (*current->getOwnId() == *person->getFatherId() || *current->getOwnId() == *person->getMotherId()) {
            markAncestors(pList, current);
        }
    }
}

void markDescendants(const PersonList &pList, const shared_ptr<Person> &person) {
    if (person == nullptr || person->getMark() == 2) return;
    person->markAs(2);

    for (const auto &current : pList.getPList()) {
        if (*current->getFatherId() == *person->getOwnId() || *current->getMotherId() == *person->getOwnId()) {
            markDescendants(pList, current);
        }
    }
}

BloodRelatives::BloodRelatives(const PersonList &pList, const Id &id) {
    auto startPerson = pList.findPerson(id);

    markAncestors(pList, startPerson);

    for (const auto &person : pList.getPList()) {
        if (person->getMark() == 1) {
            markDescendants(pList, person);
        }
    }
    for (const auto &person : pList.getPList()) {
        if (person->getMark() != 0) {
            this->addPerson(person);
        }
    }
}


