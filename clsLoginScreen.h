#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen {

private:

	static bool _Login() {

		bool loginFailed = false;
		short failedLoginCount = 0;

		string userName, password;

		do {

			if (loginFailed) {

				failedLoginCount++;
				cout << "\nInvlaid Username/Password!\n\n";
				cout << "\nYou have " << (3 - failedLoginCount) << " trial(s) to login.\n\n";
			}

			if (failedLoginCount == 3) {
				cout << "\nYou're locked after 3 failed trials \n\n";
				return false;
			}

			cout << "Enter Username? ";
			cin >> userName;

			cout << "Enter Password? ";
			cin >> password;

			currentUser = clsUser::find(userName, password); // currentUser is defined globally in Global.h on the whole system, not here
			loginFailed = currentUser.isEmpty();

		} while (loginFailed);

		clsMainScreen::showMainMenu();
	}

public:

	static bool showLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}
};