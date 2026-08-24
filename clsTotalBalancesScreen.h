#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUtil.h"

class clsTotalBalancesScreen: protected clsScreen {

private:

static void printClientRecordBalanceLine(clsBankClient client) {

    cout << setw(25) << left << "" << "| " << setw(15) << left << client.accountNumber();
    cout << "| " << setw(40) << left << client.fullName();
    cout << "| " << setw(12) << left << client.accountBalance;
}

public:

    static void showTotalBalances() {

        vector<clsBankClient> vClients = clsBankClient::getClientsList();

        string title = "\t Balances List Screen";
        string subTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";
        _DrawScreenHeader(title, subTitle);

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        double totalBalances = clsBankClient::getTotalBalances(); //calling static function 


        if (vClients.size() == 0) {
            cout << "\t\t\t\tNo Clients available in the system! ";
        }
        else {
            for (clsBankClient client : vClients) {
                printClientRecordBalanceLine(client);
                cout << endl;
            }
        }
        
        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << totalBalances << endl;
        cout << setw(8) << left << "" << "\t\t\t\t  ( " << clsUtil::numberToText(totalBalances) << ")";
    }
};

