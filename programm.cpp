#include <iostream>

#include "person.h"
#include "personlist.h"
#include "bloodrelatives.h"


int main(int argc, char *argv[]) {
    if (argc != 6) {
        std::cerr << "usage: programm <personfile> <standfile> <vorname> <nachname> <geburtsjahr>\n";
        exit(1);
    }

    PersonList pList (argv[1]);
    Id id (argv[3], argv[4], atoi(argv[5]));
    BloodRelatives bloodRel (pList, id);
    ofstream("verwandte.dat") << bloodRel;
}