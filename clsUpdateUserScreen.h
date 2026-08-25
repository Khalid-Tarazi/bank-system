#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsUpdateUserScreen: protected clsScreen {

private:

    static void _ReadUserInfo(clsUser& user) {
        cout << "\nEnter First Name: ";
        user.firstName = clsInputValidate::readString();

        cout << "\nEnter Last Name: ";
        user.lastName = clsInputValidate::readString();

        cout << "\nEnter Email: ";
        user.email = clsInputValidate::readString();

        cout << "\nEnter Phone: ";
        user.phone = clsInputValidate::readString();

        cout << "\nEnter Password: ";
        user.password = clsInputValidate::readString();

        cout << "\nEnter Permission: ";
        user.permissions = _ReadPermissionsToSet();
    }

    static void _PrintUser(clsUser user) {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirst Name   : " << user.firstName;
        cout << "\nLast Name    : " << user.lastName;
        cout << "\nFull Name   : " << user.fullName();
        cout << "\nEmail       : " << user.email;
        cout << "\nPhone       : " << user.phone;
        cout << "\nUser Name   : " << user.userName;
        cout << "\nPassword    : " << user.password;
        cout << "\nPermissions : " << user.permissions;
        cout << "\n___________________\n";
    }

    static int _ReadPermissionsToSet() {

        int permissions = 0;
        char answer = 'n';

        cout << "\nDo you want to give full access? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            permissions += clsUser::enPermissions::pUpdateClient;
        }

        cout << "\nFind Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            permissions += clsUser::enPermissions::pTransactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            permissions += clsUser::enPermissions::pManageUsers;
        }

        return permissions;
    }

public:

	static void showUpdateUserScreen() {

        _DrawScreenHeader("\tUpdate User Screen");

        string userName = "";

        cout << "\nPlease Enter User UserName: ";
        userName = clsInputValidate::readString();

        while (!clsUser::isUserExist(userName))
        {
            cout << "\nAccount number is not found, choose another one: ";
            userName = clsInputValidate::readString();
        }

        clsUser user1 = clsUser::find(userName);

        _PrintUser(user1);

        cout << "\nAre you sure you want to update this User y/n? ";

        char answer = 'n';
        cin >> answer;

        if (answer == 'y' || answer == 'Y') {
            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";

            _ReadUserInfo(user1);

            clsUser::enSaveResults saveResult;

            saveResult = user1.save();

            switch (saveResult) {
            case  clsUser::enSaveResults::svSucceeded: {
                cout << "\nUser Updated Successfully :-)\n";

                _PrintUser(user1);
                break;
            }
            case clsUser::enSaveResults::svFailedEmptyObject: {
                cout << "\nError User was not saved because it's Empty";
                break;
            }
            }
        }
	}
};

