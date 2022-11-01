#include "LoginSystem.h"
using namespace generalFunction;

int main()
{
    LoginSystem System;
    uint choice;
    bool openSystem = true;

    while (openSystem)
    {
        LoginSystem::printMainMenu();
        try
        {
            choice = setChoice(getChoice(), 3);
            clearScreen();

            (choice != 3) ? System.executeMainMenu(choice) : openSystem = false;
        }
        catch (const std::exception &e)
        {
            cerr << e.what() << endl;
        }
    }
    return 0;
}