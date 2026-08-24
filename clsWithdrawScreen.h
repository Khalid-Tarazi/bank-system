#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsWithdrawScreen: protected clsScreen {

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

    static string _ReadAccountNumber() {

        string accountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> accountNumber;
        return accountNumber;
    }

public:

	static void showWithdrawScreen() {

        _DrawScreenHeader("\tWithdraw Screen");

        string accountNumber = _ReadAccountNumber();

        while (!clsBankClient::isClientExist(accountNumber)) {
            cout << "\nClient with [" << accountNumber << "] does not exist.\n";
            accountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::find(accountNumber);
        _PrintClient(Client1);

        double amount = 0;
        cout << "\nPlease enter Withdraw amount? ";
        amount = clsInputValidate::readDblNumber();

        cout << "\nAre you sure you want to perform this transaction? y/n ";
        char answer = 'n';
        cin >> answer;

        if (answer == 'Y' || answer == 'y') {
            if (Client1.withdraw(amount)) {
                cout << "\nAmount Withdrawn Successfully.\n";
                cout << "\nNew Balance Is: " << Client1.accountBalance;
            }
            else {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmout to withdraw is: " << amount;
                cout << "\nYour Balance is: " << Client1.accountBalance;
            }
        }
        else {
            cout << "\nOperation was canceled.\n";
        }
	}
};