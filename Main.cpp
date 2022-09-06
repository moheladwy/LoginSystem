#include "LoginSystem.h"
using namespace generalFunction;

int main() {
    LoginSystem System;
    unsigned int choice;
    bool openSystem = true;

    while(openSystem) {
        LoginSystem::printMainMenu();
        try {
            choice = setChoice(getChoice(), 3);
            clearScreen();

            if (choice != 3) System.executeMainMenu(choice);
            else openSystem = false;
        }
        catch (const std::exception& e) {
            cerr << e.what() << endl;
        }
    }
    return 0;
}