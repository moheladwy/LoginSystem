#include "LoginSystem.h"
using namespace std;
using namespace OpenXLSX;
using namespace generalFunction;

void LoginSystem::printMainMenu()
{
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "Options of the main menu:-" << endl;
    cout << "--------------------------" << endl;
    cout << "1- Register." << endl;
    cout << "2- Login." << endl;
    cout << "3- Exit." << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
}

void LoginSystem::printLoginMenu()
{
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "Options of the login menu:-" << endl;
    cout << "---------------------------" << endl;
    cout << "1- Show Your Personal Data." << endl;
    cout << "2- Change Full Name." << endl;
    cout << "3- Change Phone Number." << endl;
    cout << "4- Change Email." << endl;
    cout << "5- Change Password." << endl;
    cout << "6- Logout." << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
}

void LoginSystem::showProfileData(const string &ID)
{
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "Your Personal Information:-" << endl;
    cout << "----------------------------" << endl;
    cout << "ID: " << ID << endl;
    cout << "Full Name: " << Database.getFullName(ID) << endl;
    cout << "Phone Number: " << Database.getPhoneNumber(ID) << endl;
    cout << "Email: " << Database.getEmail(ID) << endl;
    cout << "Password: " << Database.getPassword(ID) << endl;
}

LoginSystem::LoginSystem()
{
    cout << "Welcome to my Login System Project." << endl;
    Database.fetchDatabaseFile();
}

LoginSystem::~LoginSystem()
{
    printEndApp();
    Database.saveAllDataInDatabaseFile();
}

void LoginSystem::setID(const string &id)
{
    if (!(isValidID(id)) || Database.isUserExist(id))
        throw invalid_argument("Invalid argument for ID or it might be exist for someone else, Try again!.");
    profile.ID = id;
}

void LoginSystem::setFullName(const string &aName)
{
    if (!isValidFullName(aName))
        throw invalid_argument("Invalid argument for Name.");
    profile.fullName = aName;
}

void LoginSystem::setEmail(const string &anEmail)
{
    if (!(isValidEmail(anEmail)) || Database.isEmailExist(anEmail))
        throw invalid_argument("Invalid argument for Email or it might be exist for someone else, Try again!.");
    profile.email = anEmail;
}

void LoginSystem::setPassword(const string &aPassword)
{
    if (!isValidPassword(aPassword))
        throw invalid_argument("Invalid argument for Password.");
    profile.password = aPassword;
}

void LoginSystem::setPhoneNumber(const string &phone)
{
    if (!(isValidPhoneNumber(phone)) || Database.isPhoneNumberExist(phone))
        throw invalid_argument("Invalid argument for Phone Number or it might be exist for someone else, Try again!.");
    profile.phoneNumber = phone;
}

void LoginSystem::setBlockedMood(const bool &blockedMood)
{
    profile.isBlocked = blockedMood;
}

void LoginSystem::printEndApp()
{
    cout << "Thanks for using my Login System Application." << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "Author of the Project: Mohamed Hussein Hassan Eladwy." << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
}

bool LoginSystem::isValidNewFullName(const string &newName, const string &oldName)
{
    if (newName == oldName)
        cout << "The new name must be different from the old one, Try again!" << endl;
    else if (!isValidFullName(newName))
        cout << "FullName is not valid, Try again!" << endl;
    else if (newName != oldName)
    {
        cout << "Changing the Full Name Done Successfully!" << endl;
        return true;
    }
    return false;
}

void LoginSystem::changeFullName(const string &ID)
{
    User userProfile = Database.getProfile(ID);
    string newName;
    uint trails = 1;

    while (trails < 4)
    {
        newName = getFullNameForChange();
        if (isValidNewFullName(newName, userProfile.fullName))
        {
            Database.updateDatabaseMapAndSets(ID, newName, Database.getColmFullName());
            return;
        }
        trails++;
        if (trails == 4)
            cout << "You have tried to change your name 3 times, Try again later!" << endl;
    }
}

bool LoginSystem::isValidNewPhoneNumber(const string &newPhoneNumber, const string &oldPhoneNumber)
{
    if (newPhoneNumber == oldPhoneNumber)
        cout << "The new phone number must be different from the old one, Try again!" << endl;
    else if (!isValidPhoneNumber(newPhoneNumber))
        cout << "Phone Number is not valid, Try again!" << endl;
    else if (newPhoneNumber != oldPhoneNumber)
    {
        cout << "Changing the Phone Number Done Successfully!" << endl;
        return true;
    }
    return false;
}

void LoginSystem::changePhoneNumber(const string &ID)
{
    User userProfile = Database.getProfile(ID);
    string newPhoneNumber;
    uint trails = 1;

    while (trails < 4)
    {
        newPhoneNumber = getPhoneNumberForChange();
        if (isValidNewPhoneNumber(newPhoneNumber, userProfile.phoneNumber))
        {
            Database.updateDatabaseMapAndSets(ID, newPhoneNumber, Database.getColmPhoneNumber());
            return;
        }
        trails++;
        if (trails == 4)
            cout << "You have tried to change your phone number 3 times, Try again later!" << endl;
    }
}

bool LoginSystem::isValidNewEmail(const string &newEmail, const string &oldEmail)
{
    if (newEmail == oldEmail)
        cout << "The new Email must be different from the old one, Try again!" << endl;
    else if (!isValidEmail(newEmail))
        cout << "Email is not valid, Try again!" << endl;
    else if (newEmail != oldEmail)
    {
        cout << "Changing the Email Done Successfully!" << endl;
        return true;
    }
    return false;
}

void LoginSystem::changeEmail(const string &ID)
{
    User userProfile = Database.getProfile(ID);
    string newEmail;
    uint trails = 1;

    while (trails < 4)
    {
        newEmail = getEmailForChange();
        if (isValidNewEmail(newEmail, userProfile.email))
        {
            Database.updateDatabaseMapAndSets(ID, newEmail, Database.getColmEmail());
            return;
        }
        trails++;
        if (trails == 4)
            cout << "You have tried to change your name 3 times, Try again later!" << endl;
    }
}

bool LoginSystem::isValidNewPassword(const string allPasswords[])
{
    if (allPasswords[1] != allPasswords[0])
        cout << "The old Password is not correct, Try again!" << endl;
    else if (allPasswords[2] != allPasswords[3])
        cout << "The new Passwords do not matching, Try again!" << endl;
    else if (allPasswords[2] == allPasswords[0])
        cout << "The new password must be different from the old one, Try again!" << endl;
    else if (!isValidPassword(allPasswords[2]))
    {
        cout << "The new password does not follow the standard format, see it below." << endl;
        passwordFormat();
    }
    else if (allPasswords[2] != allPasswords[0])
    {
        cout << "Changing the Password Done Successfully!" << endl;
        return true;
    }
    return false;
}

void LoginSystem::changePassword(const string &ID)
{
    User userProfile = Database.getProfile(ID);
    string newPassword, allPasswords[4];
    uint trails = 1;
    allPasswords[0] = userProfile.password;

    while (trails < 4)
    {
        allPasswords[1] = getPasswordForChange("old password");
        allPasswords[2] = newPassword = getPasswordForChange("new");
        allPasswords[3] = getPasswordForChange("repeat");

        if (isValidNewPassword(allPasswords))
        {
            Database.updateDatabaseMapAndSets(ID, newPassword, Database.getColmPassword());
            return;
        }
        trails++;
        if (trails == 4)
            cout << "You have tried to change your password 3 times and goes wrong, Try again later!" << endl;
    }
}

void LoginSystem::getIDForRegister(uint &trails, bool &isCorrect)
{
    try
    {
        string ID;
        cout << "Enter the ID: ";
        getline(cin, ID);
        makeLowerCase(ID);
        setID(ID);
        isCorrect = true;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
        trails++;
    }
}

void LoginSystem::getPasswordForRegister(uint &trails, bool &isCorrect)
{
    try
    {
        passwordFormat();
        string password, repeatedPassword;
        cout << "Enter the password: ";
        getline(cin, password);
        cout << "Re-Enter the password: ";
        getline(cin, repeatedPassword);
        if (password == repeatedPassword)
        {
            setPassword(password);
            isCorrect = true;
        }
        else
            throw invalid_argument("the password does not match, Try again!");
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
        trails++;
    }
}

void LoginSystem::getEmailForRegister(uint &trails, bool &isCorrect)
{
    try
    {
        string email;
        cout << "Enter the email: ";
        getline(cin, email);
        makeLowerCase(email);
        setEmail(email);
        isCorrect = true;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
        trails++;
    }
}

void LoginSystem::getPhoneNumberForRegister(uint &trails, bool &isCorrect)
{
    try
    {
        string ID;
        cout << "Enter the phone number: ";
        getline(cin, ID);
        setPhoneNumber(ID);
        isCorrect = true;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
        trails++;
    }
}

void LoginSystem::getFullNameForRegister(uint &trails, bool &isCorrect)
{
    try
    {
        string fullName;
        cout << "Enter the full name: ";
        getline(cin, fullName);
        setFullName(fullName);
        isCorrect = true;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
        trails++;
    }
}

void LoginSystem::LoginBoard(const string &ID)
{
    uint choice;
    bool isLogin = true;

    while (isLogin)
    {
        printLoginMenu();
        try
        {
            choice = setChoice(getChoice(), 6);
            clearScreen();

            if (choice != 6)
                executeLoginMenu(choice, ID);
            else
                isLogin = false;
        }
        catch (const exception &e)
        {
            cerr << e.what() << endl;
        }
    }
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "You have logged out from the system!" << endl;
}

void LoginSystem::Register()
{
    uint trails = 1;
    bool isCorrect = false;

    while (trails <= 3 && !isCorrect)
        getFullNameForRegister(trails, isCorrect);
    if (isTrailsCompleted(trails, "full name", isCorrect))
        return;

    while (trails <= 3 && !isCorrect)
        getPhoneNumberForRegister(trails, isCorrect);
    if (isTrailsCompleted(trails, "phone number", isCorrect))
        return;

    while (trails <= 3 && !isCorrect)
        getIDForRegister(trails, isCorrect);
    if (isTrailsCompleted(trails, "ID", isCorrect))
        return;

    while (trails <= 3 && !isCorrect)
        getEmailForRegister(trails, isCorrect);
    if (isTrailsCompleted(trails, "email", isCorrect))
        return;

    while (trails <= 3 && !isCorrect)
        getPasswordForRegister(trails, isCorrect);
    if (isTrailsCompleted(trails, "password", isCorrect))
        return;

    setBlockedMood(false);
    Database.insertProfileIntoMapAndSets(profile);
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "You have been registered successfully to the system!" << endl;
    LoginBoard(profile.ID);
}

void LoginSystem::getIDForLogin(string &ID, uint &trails, bool &isCorrect)
{
    try
    {
        cout << "Enter the ID: ";
        getline(cin, ID);
        if (Database.isUserExist(ID) == 0)
            throw invalid_argument("The ID does not exist, please register or try again with different ID.");
        isCorrect = true;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
        trails++;
    }
}

void LoginSystem::getPasswordForLogin(string &password, const string &ID, uint &trails, bool &isCorrect)
{
    try
    {
        cout << "Enter the password: ";
        getline(cin, password);
        if (Database.getPassword(ID) != password)
            throw invalid_argument("The Password is not correct, Try again!");
        isCorrect = true;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
        trails++;
    }
}

void LoginSystem::executeLoginMenu(ucint &choice, const string &ID)
{
    if (choice == 1)
        showProfileData(ID);
    else if (choice == 2)
        changeFullName(ID);
    else if (choice == 3)
        changePhoneNumber(ID);
    else if (choice == 4)
        changeEmail(ID);
    else if (choice == 5)
        changePassword(ID);
}

void LoginSystem::Login()
{
    uint trails = 1;
    string ID, password;
    bool isCorrect = false;

    while (trails <= 3 && !isCorrect)
        getIDForLogin(ID, trails, isCorrect);
    if (isTrailsCompleted(trails, "ID to login", isCorrect))
        return;
    if (Database.isBlocked(ID))
        return;

    while (trails <= 3 && !isCorrect)
        getPasswordForLogin(password, ID, trails, isCorrect);
    if (isTrailsCompleted(trails, "password to login", isCorrect))
    {
        cout << "You are blocked from the system for security concerns." << endl;
        cout << "Try again later or contact with support!" << endl;
        Database.blockUser(ID);
        return;
    }
    if (Database.isBlocked(ID))
        return;
    LoginBoard(ID);
}

void LoginSystem::executeMainMenu(ucint &choice)
{
    (choice == 1) ? Register() : Login();
}