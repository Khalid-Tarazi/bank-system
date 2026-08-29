#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen: protected clsScreen {

private:

    static void _PrintClient(clsBankClient client) {
        cout << "\nClient Card:";
        cout << "\n___________________\n";
        cout << "\nFull Name   : " << client.fullName();
        cout << "\nAcc. Number : " << client.accountNumber();
        cout << "\nBalance     : " << client.accountBalance;
        cout << "\n___________________\n";
    }

    static string _ReadAccountNumber() {
        string accountNumber;
        cout << "\nPlease Enter Account Number to Transfer From: ";
        accountNumber = clsInputValidate::readString();
        
        while (!clsBankClient::isClientExist(accountNumber)) {
            cout << "\nAccount number is not found, choose another one: ";
            accountNumber = clsInputValidate::readString();
        }
        return accountNumber;
    }

    static float readAmount(clsBankClient sourceClient) {
        
        float amount;

        cout << "\nEnter Transfer Amount? ";

        amount = clsInputValidate::readFloatNumber();

        while (amount > sourceClient.accountBalance) {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            amount = clsInputValidate::readDblNumber();
        }
        return amount;
    }

public:

	static void showTransferScreen() {

        _DrawScreenHeader("\tTransfer Screen");
        clsBankClient sourceClient = clsBankClient::find(_ReadAccountNumber());
        _PrintClient(sourceClient);
        clsBankClient destinationClient = clsBankClient::find(_ReadAccountNumber());
        _PrintClient(destinationClient);

        float amount = readAmount(sourceClient);

        cout << "\nAre you sure you want to perform this operation? y/n? ";
        char answer = 'n';
        cin >> answer;

        if (answer == 'Y' || answer == 'y') {
            if (sourceClient.transfer(amount, destinationClient)) {
                cout << "\nTransfer done successfully\n";
            }
            else {
                cout << "\nTransfer Failed \n";
            }
        }
        
        _PrintClient(sourceClient);
        _PrintClient(destinationClient);
	}
};

