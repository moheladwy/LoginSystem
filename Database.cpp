#include "Database.h"

using namespace std;
using namespace OpenXLSX;
using namespace generalFunction;

unsigned int Database::getColmEmail() const { return colmEmail; }
unsigned int Database::getColmPhoneNumber() const { return colmPhoneNumber; }
unsigned int Database::getColmPassword() const { return colmPassword; }
unsigned int Database::getColmFullName() const { return colmFullName; }

User   Database::getProfile(const string& ID) { return database[ID]; }
string Database::getEmail(const string &ID) {return database[ID].email;}
string Database::getFullName(const string &ID) {return database[ID].fullName;}
string Database::getPhoneNumber(const string &ID) {return database[ID].phoneNumber;}
string Database::getPassword(const string& ID) { return database[ID].password; }

bool Database::isUserExist(const string& ID) {
    if (database.count(ID)) return true;
    return false;
}

bool Database::isEmailExist(const string& email) {
    if (registeredEmails.count(email)) return true;
    return false;
}

bool Database::isPhoneNumberExist(const string& phoneNumber) {
    if (registeredPhoneNumbers.count(phoneNumber)) return true;
    return false;
}

bool Database::isBlocked(const string& ID) {
    if (database[ID].isBlocked)
        cout << "You are blocked from the system, Try again later or contact with support!" << endl;
    return database[ID].isBlocked;
}

void Database::fetchProfileFromDatabase(User& profile, XLWorksheet& workSheet, unsigned int const& index) const {
    profile.rowID = index;
    profile.ID = workSheet.cell(index, colmID).value().get<string>();
    profile.fullName = workSheet.cell(index, colmFullName).value().get<string>();
    profile.phoneNumber = workSheet.cell(index, colmPhoneNumber).value().get<string>();
    profile.email = workSheet.cell(index, colmEmail).value().get<string>();
    profile.password = workSheet.cell(index, colmPassword).value().get<string>();
    profile.password = decryptPassword(profile.password);
    profile.isBlocked = workSheet.cell(index, colmBlocked).value().get<bool>();
}

void Database::insertProfileIntoMapAndSets(User& profile) {
    database.insert({ profile.ID, profile });
    registeredEmails.insert(profile.email);
    registeredPhoneNumbers.insert(profile.phoneNumber);
}

void Database::fetchDatabaseFile() {
    User profile;
    XLDocument usersData;
    usersData.open("usersData.xlsx");
    XLWorksheet workSheet = usersData.workbook().worksheet("Sheet1");

    for (unsigned int index = 2; index <= workSheet.rowCount(); ++index) {
        fetchProfileFromDatabase(profile, workSheet, index);
        insertProfileIntoMapAndSets(profile);
    }
    usersData.close();
}

void Database::updateEmail(const string& newEmail, User& tempProfile) {
    // Edit the Value -> email, in the registeredEmails set
    auto oldEmail = registeredEmails.extract(tempProfile.email);
    oldEmail.value() = newEmail;
    registeredEmails.insert(move(oldEmail));

    // Edit the Email in the getUsersData map and the Excel file.
    tempProfile.email = newEmail;
}

void Database::updatePhoneNumber(const string& newPhoneNumber, User& tempProfile) {
    // Edit the Value -> Phone Number, in the registeredPhoneNumbers set
    auto oldPhoneNumber = registeredPhoneNumbers.extract(tempProfile.phoneNumber);
    oldPhoneNumber.value() = newPhoneNumber;
    registeredPhoneNumbers.insert(move(oldPhoneNumber));

    // Edit the Phone Number in the getUsersData map and the Excel file.
    tempProfile.phoneNumber = newPhoneNumber;
}

void Database::updateDatabaseMapAndSets(const string& ID, const string& infoWantedToChange, unsigned const int& choice) {
    User tempProfile = database[ID];

    if (choice == 2) tempProfile.fullName = infoWantedToChange;
    else if (choice == 3) updatePhoneNumber(infoWantedToChange, tempProfile);
    else if (choice == 4) updateEmail(infoWantedToChange, tempProfile);
    else if (choice == 5) tempProfile.password = infoWantedToChange;

    database[ID] = tempProfile;
}

void Database::blockUser(const string &ID) {
    if (!(database[ID].isBlocked)) database[ID].isBlocked = true;
}

void Database::setProfileInDatabaseFile(User& userProfile, XLWorksheet& workSheet) const {
    workSheet.cell(userProfile.rowID, colmID).value() = userProfile.ID;
    workSheet.cell(userProfile.rowID, colmFullName).value() = userProfile.fullName;
    workSheet.cell(userProfile.rowID, colmPhoneNumber).value() = userProfile.phoneNumber;
    workSheet.cell(userProfile.rowID, colmEmail).value() = userProfile.email;
    workSheet.cell(userProfile.rowID, colmPassword).value() = encryptPassword(userProfile.password);
    workSheet.cell(userProfile.rowID, colmBlocked).value() = userProfile.isBlocked;
}

void Database::updateDatabaseFile(XLWorksheet& workSheet) {
    unsigned int rowID = 2;
    for (pair userProfile : database) {
        userProfile.second.rowID = rowID; rowID++;
        setProfileInDatabaseFile(userProfile.second, workSheet);
    }
}

void Database::saveAllDataInDatabaseFile() {
    XLDocument usersData;
    usersData.open("usersData.xlsx");
    XLWorksheet workSheet = usersData.workbook().worksheet("Sheet1");

    updateDatabaseFile(workSheet);

    usersData.save();
    usersData.close();
}