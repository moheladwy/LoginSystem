#include "generalFunctions.h"
using namespace std;

bool generalFunction::isValidChoice(const string &choice, unsigned const int &endRange) {
    if (endRange == 3) {
        regex isValid("^[123]{1}$");
        return regex_match(choice, isValid);
    }
    regex isValid("^[1-6]{1}$");
    return regex_match(choice, isValid);
}

bool generalFunction::isValidID(const string &ID) {
    regex isValid(R"(^[\w\.\-\#\!\%\$\&\+\*\/\=\?\^\`\{\|\}\~]*$)");
    return regex_match(ID, isValid);
}

bool generalFunction::isValidFullName(const string &fullName) {
    regex isValid("^[a-zA-Z]+([ -]?[A-Za-z]*)+$");
    return regex_match(fullName, isValid);
}

bool generalFunction::isValidPhoneNumber(const string &phoneNumber) {
    regex isValid("^01[0125][0-9]{8}$");
    return regex_match(phoneNumber, isValid);
}

bool generalFunction::isValidEmail(const string &email) {
    regex isValid("^\\w{1}([\\.\\-\\#\\!\\%\\$\\‘\\&\\+\\*\\/\\=\\?\\^\\_\\`\\{\\|\\}\\~]?\\w+){0,63}@\\w+([.-]?\\w+)*(\\.\\w{2,3})+$");
    return regex_match(email, isValid);
}

bool generalFunction::isValidPassword(const string &password) {
    regex passwordFormat("^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[#<>=?/!+@$%^&*-]).{8,256}$");
    return regex_match(password, passwordFormat);
}

void generalFunction::clearScreen() {
    system("CLS");
    cout << flush;
    system("CLS");
}

string generalFunction::encryptPassword(const string &decryptedPassword) {
    string pass; pass = "";
    for (char i : decryptedPassword) {
        if (isupper(i))
            i = char (int (i) + 25 - 2 * int (i - 'A')); // equation to get new cipher letter
        else if (islower(i))
            i = char (int (i) + 25 - 2 * int (i - 'a'));
        pass += i;
    }
    return pass;
}

string generalFunction::decryptPassword(const string &encryptedPassword) {
    string pass; pass = "";
    for (char i : encryptedPassword) {
        if (isupper(i))
            i = char(int(i) - 25 + 2 * int('Z' - i)); // equation to get new cipher letter
        else if (islower(i))
            i = char(int(i) - 25 + 2 * int('z' - i));
        pass += i;
    }
    return pass;
}

string generalFunction::getChoice() {
    string choice;
    cout << "Enter Your choice: ";
    getline(cin, choice);
    return choice;
}

unsigned int generalFunction::setChoice(const string &choice, unsigned const int &endRange) {
    if (!isValidChoice(choice, endRange))
        throw invalid_argument("incorrect choice, please choose a valid choice.");
    return stoi(choice);
}

string generalFunction::getFullNameForChange() {
    string fullName;
    cout << "Enter the full name: ";
    getline(cin, fullName);
    return fullName;
}

string generalFunction::getPhoneNumberForChange() {
    string phoneNumber;
    cout << "Enter the phone number: ";
    getline(cin, phoneNumber);
    return phoneNumber;
}

string generalFunction::getEmailForChange() {
    string email;
    cout << "Enter the email: ";
    getline(cin, email);
    return email;
}

string generalFunction::getPasswordForChange(const string& passwordType = "") {
    string password;
    if (passwordType == "old password")
        cout << "Enter the old password: ";
    else if (passwordType == "repeat")
        cout << "Re-Enter the new password: ";
    else
        cout << "Enter the new password: ";
    getline(cin, password);
    return password;
}

bool generalFunction::isTrailsCompleted(unsigned int &trails, const string &thing, bool &isCorrect) {
    if(trails == 4) {
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "You tried to type the " << thing << " 3 times and goes wrong!" << endl;
        return true;
    }
    isCorrect = false;
    trails = 1;
    return false;
}

void generalFunction::passwordFormat() {
    cout << "--------------------------------------------------------" << endl;
    cout << "The password must contain:" << endl;
    cout << "--------------------------" << endl;
    cout << "1- Small letters (a, b ..etc)." << endl;
    cout << "2- Capital letters (A, B ..etc)." << endl;
    cout << "3- Numbers (0, 1 ..etc)." << endl;
    cout << "4- Special characters(@, #..etc)." << endl;
    cout << "5- Be 8 or more characters and less that 256 characters." << endl;
    cout << "--------------------------------------------------------" << endl;
}