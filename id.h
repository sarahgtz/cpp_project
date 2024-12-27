#ifndef ID_H
#define ID_H

#include <iostream>

using namespace std;

/** Unique ID of a person contains firstname, lastname and birthyear */
class Id {
public:
    Id (const string &firstname, const string &lastname, unsigned birthyear);

    string getFirstname() const { return firstname; }
    string getLastname() const { return lastname; }
    unsigned getBirthyear() const { return birthyear; }

    bool operator==(const Id &other) const;
    bool operator<(const Id &other) const;

    void print(ostream &o = cout) const ;

private:
    string firstname, lastname;
    unsigned birthyear;
};

inline ostream &operator<<(ostream &o, const Id &id) {
    id.print(o);
    return o;
}

#endif
