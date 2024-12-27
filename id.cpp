#include "id.h"

Id::Id (const string &firstname, const string &lastname, unsigned birthyear)
        : firstname(firstname), lastname(lastname), birthyear(birthyear) {}


bool Id::operator==(const Id &other) const {
    return birthyear == other.birthyear && firstname == other.firstname && lastname == other.lastname;
}

bool Id::operator<(const Id &other) const {
    if (birthyear != other.birthyear) return birthyear < other.birthyear;
    if (lastname != other.lastname) return lastname < other.lastname;
    return firstname < other.firstname;
}

void Id::print(ostream &o) const {
    o << firstname << " " << lastname << " " << birthyear;
}
