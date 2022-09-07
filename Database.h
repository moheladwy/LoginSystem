#ifndef DATABASE_H
#define DATABASE_H

#include <unordered_map>
#include <unordered_set>
#include "OpenXLSX.hpp"
#include "generalFunctions.h"
using namespace std;
using namespace OpenXLSX;

struct User {
	string fullName, phoneNumber, email, password, ID;
	bool isBlocked = false;
	unsigned int rowID = 0;
};

class Database {
public:
	unsigned int getColmFullName() const;
	unsigned int getColmPhoneNumber() const;
	unsigned int getColmPassword() const;
	unsigned int getColmEmail() const;

	User getProfile(const string&);
	string getPassword(const string&);
    	string getEmail(const string &);
    	string getPhoneNumber(const string &);
    	string getFullName(const string &);


	bool isUserExist(const string&);
	bool isEmailExist(const string&);
	bool isPhoneNumberExist(const string&);
	bool isBlocked(const string&);

	void fetchProfileFromDatabase(User&, XLWorksheet&, unsigned int const&) const;
	void fetchDatabaseFile();

	void insertProfileIntoMapAndSets(User&);
    	void blockUser(const string &ID);
	void updateEmail(const string&, User&);
	void updatePhoneNumber(const string&, User&);
	void updateDatabaseMapAndSets(const string&, const string&, unsigned const int&);

	void setProfileInDatabaseFile(User &userProfile, XLWorksheet &workSheet) const;
	void updateDatabaseFile(XLWorksheet&);
	void saveAllDataInDatabaseFile();

private:
	unsigned const int colmID = 1, colmFullName = 2, colmPhoneNumber = 3, colmEmail = 4, colmPassword = 5, colmBlocked = 6;

	unordered_map<string, User> database;
	unordered_set<string> registeredEmails;
	unordered_set<string> registeredPhoneNumbers;
};
#endif
