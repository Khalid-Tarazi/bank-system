#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "global.h"

class clsLoginScreen: protected clsScreen {

private:

    static void _Login() {

        bool loginFailed = false;

        string userName, password;

        do {
            
            if (loginFailed) {
                cout << "\nInvlaid Username/Password!\n\n";
            }

            cout << "Enter Username? ";
            cin >> userName;

            cout << "Enter Password? ";
            cin >> password;

            currentUser = clsUser::find(userName, password); // currentUser is defined globally in global.h on the whole system, not here
            loginFailed = currentUser.isEmpty();

        } while (loginFailed);
        clsMainScreen::showMainMenu();
    }

public:

    static void showLoginScreen() {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        _Login();
    }
};

