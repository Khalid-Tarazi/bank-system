#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen: protected clsScreen {

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

    static void ShowUpdateClientScreen() {

        if (!checkAccessRights(clsUser::enPermissions::pAddNewClient)) {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tUpdate Client Screen");

        string accountNumber = "";

        cout << "\nPlease enter account number: ";
        accountNumber = clsInputValidate::readString();

        while (!clsBankClient::isClientExist(accountNumber)) {
            cout << "\nPlease enter account number: ";
            accountNumber = clsInputValidate::readString();
        }

        clsBankClient client1 = clsBankClient::find(accountNumber);
        _PrintClient(client1);

        cout << "\n\nUpdate client info:";
        cout << "\n_____________________\n";

        _ReadClientInfo(client1);

        clsBankClient::enSaveResults saveResult;

        saveResult = client1.save();

        switch (saveResult) {

        case clsBankClient::svSucceeded: {
            cout << "\nAccount updated successfully\n";
            _PrintClient(client1);
            break;
        }
        case clsBankClient::svFailedEmptyObject: {
            cout << "\nError account was not saved because it's empty";
            break;
        }
        }
    }
};

