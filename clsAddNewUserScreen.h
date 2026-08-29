#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsAddNewUserScreen : protected clsScreen  {

private:

    static void _ReadUserInfo(clsUser& user) {
        cout << "\nEnter FirstName: ";
        user.firstName = clsInputValidate::readString();

        cout << "\nEnter LastName: ";
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

        cout << "\nShow Login Register? y/n? ";
        cin >> answer;
        
        if (answer == 'Y' || answer == 'y') {
            permissions += clsUser::enPermissions::pShowLogInRegister;
        }

        return permissions;
    }

public:

	static void showAddNewUserScreen() {

		string userName = "";

		cout << "\nPlease Enter UserName: ";
		userName = clsInputValidate::readString();

		while (clsUser::isUserExist(userName)) {
			cout << "\nUserName Is Already Used, Choose Another One: ";
			userName = clsInputValidate::readString();
		}

		clsUser newUser = clsUser::getAddNewUserObject(userName);

		_ReadUserInfo(newUser);

		clsUser::enSaveResults saveResult;

		saveResult = newUser.save();

        switch (saveResult) {
        case  clsUser::enSaveResults::svSucceeded:{
            cout << "\nUser Added Successfully :-)\n";
            _PrintUser(newUser);
            break;
        }
        case clsUser::enSaveResults::svFailedEmptyObject: {
            cout << "\nError: User was not saved because it's Empty";
            break;
        }
        case clsUser::enSaveResults::svFailedUserExists: {
            cout << "\nError: User was not saved because UserName is used!\n";
            break;
        }
        }
	}
};

