#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen: protected clsScreen {

private:

    static void _PrintUser(clsUser user) {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << user.firstName;
        cout << "\nLastName    : " << user.lastName;
        cout << "\nFull Name   : " << user.fullName();
        cout << "\nEmail       : " << user.email;
        cout << "\nPhone       : " << user.phone;
        cout << "\nUserName    : " << user.userName;
        cout << "\nPassword    : " << user.password;
        cout << "\nPermissions : " << user.permissions;
        cout << "\n___________________\n";
    }

public:

    static void showFindUserScreen() {

        _DrawScreenHeader("\t  Find User Screen");

        string userName;
        cout << "\nPlease enter user name: ";
        userName = clsInputValidate::readString();

        while (!clsUser::isUserExist(userName)) {
            
            cout << "\nUser is not found, choose another one: ";
            userName = clsInputValidate::readString();
        }

        clsUser user1 = clsUser::find(userName);

        if (!user1.isEmpty()) {
            cout << "\nUser Found :-)\n";
        }
        else {
            cout << "\nUser Was not Found :-(\n";
        }

        _PrintUser(user1);
    } 
};

