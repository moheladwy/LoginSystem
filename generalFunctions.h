#ifndef GENERALFUNCTIONS_H
#define GENERALFUNCTIONS_H

#include <iostream>
#include <regex>
using namespace std;

namespace generalFunction {
    bool isValidChoice(const string&, unsigned const int&);
    bool isValidID(const string&);
    bool isValidFullName(const string&);
    bool isValidPhoneNumber(const string&);
    bool isValidEmail(const string&);
    bool isValidPassword(const string&);
    bool isTrailsCompleted(unsigned int &, const string &, bool &);

    unsigned int setChoice(const string &choice, unsigned const int &endRange);
    void clearScreen();
    void passwordFormat();
    void makeLowerCase(string&);

    string getChoice();
    string getFullNameForChange();
    string getPhoneNumberForChange();
    string getEmailForChange();
    string getPasswordForChange(const string&);
    string encryptPassword(const string&);
    string decryptPassword(const string&);
}
#endif // !GENERALFUNCTIONS_H