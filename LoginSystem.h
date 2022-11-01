#ifndef LOGINSYSTEM_H
#define LOGINSYSTEM_H

#include "Database.h"
using namespace std;
using namespace OpenXLSX;

// typedef unsigned int uint;
// typedef unsigned const int ucint;

class LoginSystem
{
public:
    LoginSystem();
    ~LoginSystem();

    void executeMainMenu(ucint &choice);
    static void printMainMenu();

private:
    User profile;
    Database Database;

    void setID(const string &);
    void setFullName(const string &);
    void setPhoneNumber(const string &);
    void setEmail(const string &);
    void setPassword(const string &);
    void setBlockedMood(const bool &);

    void getIDForRegister(uint &, bool &);
    void getFullNameForRegister(uint &, bool &);
    void getEmailForRegister(uint &, bool &);
    void getPasswordForRegister(uint &, bool &);
    void getPhoneNumberForRegister(uint &, bool &);

    void getIDForLogin(string &, uint &, bool &);
    void getPasswordForLogin(string &password, const string &ID, uint &, bool &);

    static void printLoginMenu();
    static void printEndApp();

    static bool isValidNewFullName(const string &, const string &);
    static bool isValidNewPassword(const string[]);
    static bool isValidNewEmail(const string &, const string &);
    static bool isValidNewPhoneNumber(const string &, const string &);

    void showProfileData(const string &);
    void changeFullName(const string &);
    void changePhoneNumber(const string &);
    void changeEmail(const string &);
    void changePassword(const string &);

    void executeLoginMenu(ucint &choice, const string &ID);
    void Register();
    void LoginBoard(const string &);
    void Login();
};
#endif