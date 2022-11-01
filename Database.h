#ifndef DATABASE_H
#define DATABASE_H

#include <unordered_map>
#include <unordered_set>
#include "OpenXLSX.hpp"
#include "generalFunctions.h"
using namespace std;
using namespace OpenXLSX;

#define colmID 1
#define colmFullName = 2
#define colmPhoneNumber = 3
#define colmEmail = 4
#define colmPassword = 5
#define colmBlocked = 6

typedef unsigned int uint;
typedef unsigned const int ucint;

struct User
{
	string fullName, phoneNumber, email, password, ID;
	bool isBlocked = false;
	uint rowID = 0;
};

class Database
{
public:
	User getProfile(const string &);
	string getPassword(const string &);
	string getEmail(const string &);
	string getPhoneNumber(const string &);
	string getFullName(const string &);

	bool isUserExist(const string &);
	bool isEmailExist(const string &);
	bool isPhoneNumberExist(const string &);
	bool isBlocked(const string &);

	void fetchProfileFromDatabase(User &, XLWorksheet &, uint const &) const;
	void fetchDatabaseFile();

	void insertProfileIntoMapAndSets(User &);
	void blockUser(const string &ID);
	void updateEmail(const string &, User &);
	void updatePhoneNumber(const string &, User &);
	void updateDatabaseMapAndSets(const string &, const string &, ucint &);

	void setProfileInDatabaseFile(User &userProfile, XLWorksheet &workSheet) const;
	void updateDatabaseFile(XLWorksheet &);
	void saveAllDataInDatabaseFile();

private:
	unordered_map<string, User> database;
	unordered_set<string> registeredEmails;
	unordered_set<string> registeredPhoneNumbers;
};
#endif
