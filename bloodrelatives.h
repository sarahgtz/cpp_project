#ifndef BLOODRELATIVES_H
#define BLOODRELATIVES_H

#include "personlist.h"

using namespace std;

/** A list of blood relatives - inherits from PersonList */
class BloodRelatives : public PersonList{
public:
    BloodRelatives(const PersonList &pList, const Id &id);
};

#endif
