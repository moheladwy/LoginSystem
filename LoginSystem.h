#ifndef LOGINSYSTEM_H
#define LOGINSYSTEM_H

#include "Database.h"
using namespace std;
using namespace OpenXLSX;

class LoginSystem
{
public:
    LoginSystem();
    ~LoginSystem();

    void executeMainMenu(unsigned const int &choice);
    static void printMainMenu();

private:
    User profile;
    Database Database;

    void setID(const string&);
    void setFullName(const string&);
    void setPhoneNumber(const string&);
    void setEmail(const string&);
    void setPassword(const string&);
    void setBlockedMood(const bool&);

    void getIDForRegister(unsigned int &, bool &);
    void getFullNameForRegister(unsigned int &, bool &);
    void getEmailForRegister(unsigned int &, bool &);
    void getPasswordForRegister(unsigned int &, bool &);
    void getPhoneNumberForRegister(unsigned int &, bool &);

    void getIDForLogin(string &, unsigned int &, bool &);
    void getPasswordForLogin(string &password, const string &ID, unsigned int &, bool &);

    static void printLoginMenu();
    static void printEndApp();

    static bool isValidNewFullName(const string&, const string&);
    static bool isValidNewPassword(const string[]);
    static bool isValidNewEmail(const string&, const string&);
    static bool isValidNewPhoneNumber(const string&, const string&);

    void showProfileData(const string&);
    void changeFullName(const string &);
    void changePhoneNumber(const string &);
    void changeEmail(const string &);
    void changePassword(const string &);

    void executeLoginMenu(unsigned const int &choice, const string &ID);
    void Register();
    void LoginBoard(const string &);
    void Login();
};
#endif