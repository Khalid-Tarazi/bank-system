#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDeleteClientScreen: protected clsScreen {

private:

    static void _PrintClient(clsBankClient client) {

        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << client.firstName;
        cout << "\nLastName    : " << client.lastName;
        cout << "\nFull Name   : " << client.fullName();
        cout << "\nEmail       : " << client.email;
        cout << "\nPhone       : " << client.phone;
        cout << "\nAcc. Number : " << client.accountNumber();
        cout << "\nPassword    : " << client.pinCode;
        cout << "\nBalance     : " << client.accountBalance;
        cout << "\n___________________\n";
    }
    
public:

	static void showDeleteClientScreen() { // return true or false, and return empty object, and it deletes from file.
		
        if (!checkAccessRights(clsUser::enPermissions::pAddNewClient)) {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tDelete Client Screen");

        string accountNumber = "";

        cout << "\nPlease enter account number: ";
        accountNumber = clsInputValidate::readString();
        while (!clsBankClient::isClientExist(accountNumber)) {
            cout << "\nAccount is not found, choose another one: ";
            accountNumber = clsInputValidate::readString();
        }

        clsBankClient client1 = clsBankClient::find(accountNumber);
        _PrintClient(client1);

        cout << "\nAre you sure you want to delete this client? y/n ";

        char answer = 'n';
        cin >> answer;

        if (answer == 'y' || answer == 'Y') {
            if (client1.Delete()) {  // I have to rename to Delete, or else I will get conflict with delete() bulit in function
                cout << "\nClient deleted successfully\n";
                _PrintClient(client1); // to show the object
            }
            else {
                cout << "\nError client was not deleted\n";
            }
        }
	}
};

