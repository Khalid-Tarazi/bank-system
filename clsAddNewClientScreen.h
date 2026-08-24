#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsAddNewClientScreen: protected clsScreen {

private:

    static void _ReadClientInfo(clsBankClient& client) {

        cout << "\nEnter first name: ";
        client.firstName = clsInputValidate::readString();

        cout << "\nEnter last name: ";
        client.lastName = clsInputValidate::readString();

        cout << "\nEnter email: ";
        client.email = clsInputValidate::readString();

        cout << "\nEnter phone: ";
        client.phone = clsInputValidate::readString();

        cout << "\nEnter pin Code: ";
        client.pinCode = clsInputValidate::readString();

        cout << "\nEnter account balance: ";
        client.accountBalance = clsInputValidate::readFloatNumber();
    }

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

    static void showAddNewClientScreen() {

        _DrawScreenHeader("\t  Add New Client Screen");

        string accountNumber = "";

        cout << "\nPlease enter account number: ";
        accountNumber = clsInputValidate::readString();
        while (clsBankClient::isClientExist(accountNumber)) {

            cout << "\nAccount number is already used, choose another one: ";
            accountNumber = clsInputValidate::readString();
        }

        clsBankClient newClient = clsBankClient::getAddNewClientObject(accountNumber);

        _ReadClientInfo(newClient);

        clsBankClient::enSaveResults saveResult;

        saveResult = newClient.save(); // added new mode

        switch (saveResult) {

        case clsBankClient::enSaveResults::svSucceeded: {
            cout << "\nAccount added successfully\n";
            _PrintClient(newClient); // i stopped using the print() function in clsBankClient.h
            break;
        }

        case clsBankClient::enSaveResults::svFailedEmptyObject: {
            cout << "\nError: account was not saved because the object is empty.";
            break;
        }

        case clsBankClient::enSaveResults::svFailedAccountNumberExists: {
            cout << "\nError account was not saved because account number is used!\n";
            break;
        }
        }
    }

};

