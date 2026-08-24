#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsFindClientScreen: protected clsScreen {

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

    static void showFindClientScreen() {

        _DrawScreenHeader("\tFind Client Screen");

        string accountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        accountNumber = clsInputValidate::readString();
        
        while (!clsBankClient::isClientExist(accountNumber)) {
            cout << "\nAccount number is not found, choose another one: ";
            accountNumber = clsInputValidate::readString();
        }

        clsBankClient client1 = clsBankClient::find(accountNumber);

        if (!client1.isEmpty()) {
            cout << "\nClient found!\n";
        }
        else {
            cout << "\nClient not found!\n";
        }

        _PrintClient(client1);
    }
};

