#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen: protected clsScreen {

private:

    static void _PrintUser(clsUser user) {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << user.firstName;
        cout << "\nLastName    : " << user.lastName;
        cout << "\nFull Name   : " << user.fullName();
        cout << "\nEmail       : " << user.email;
        cout << "\nPhone       : " << user.phone;
        cout << "\nUser Name   : " << user.userName;
        cout << "\nPassword    : " << user.password;
        cout << "\nPermissions : " << user.permissions;
        cout << "\n___________________\n";
    }

public:

	static void showDeleteUserScreen() {

        _DrawScreenHeader("\tDelete User Screen");

        string userName = "";

        cout << "\nPlease Enter User Name: ";
        userName = clsInputValidate::readString();

        while (!clsUser::isUserExist(userName)) {
            cout << "\nUser is not found, choose another one: ";
            userName = clsInputValidate::readString();
        }

        clsUser user1 = clsUser::find(userName);
        _PrintUser(user1);

        cout << "\nAre you sure you want to delete this user y/n? ";

        char answer = 'n';
        cin >> answer;

        if (answer == 'y' || answer == 'Y') {

            if (user1.Delete()) {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(user1);
            }
            else {
                cout << "\nError User Was not Deleted\n";
            }
        }
	}
};