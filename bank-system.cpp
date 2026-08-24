#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include <iomanip>
#include "clsMainScreen.h"

using namespace std;

//void printClientRecordBalanceLine(clsBankClient client) {
//
//    cout << "| " << setw(15) << left << client.accountNumber();
//    cout << "| " << setw(40) << left << client.fullName();
//    cout << "| " << setw(12) << left << client.accountBalance;
//}

//void updateClient() {
//
//    string accountNumber = "";
//
//    cout << "\nPlease enter account number: ";
//    accountNumber = clsInputValidate::readString();
//
//    while (!clsBankClient::isClientExist(accountNumber)) {
//        cout << "\nPlease enter account number: ";
//        accountNumber = clsInputValidate::readString();
//    }
//
//    clsBankClient client1 = clsBankClient::find(accountNumber);
//    client1.print();
//
//    cout << "\n\nUpdate client info:";
//    cout << "\n_____________________\n";
//
//    readClientInfo(client1);
//
//    clsBankClient::enSaveResults saveResult;
//
//    saveResult = client1.save();
//
//    switch (saveResult) {
//
//    case clsBankClient::svSucceeded: {
//        cout << "\nAccount updated successfully\n";
//        client1.print();
//        break;
//    }
//    case clsBankClient::svFailedEmptyObject: {
//        cout << "\nError account was not saved because it's empty";
//        break;
//    }
//    }
//}

//void showTotalBalances() {
//
//    vector<clsBankClient> vClients = clsBankClient::getClientsList();
//
//    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
//    cout << "\n_______________________________________________________";
//    cout << "_________________________________________\n" << endl;
//
//    cout << "| " << left << setw(15) << "Account Number";
//    cout << "| " << left << setw(40) << "Client Name";
//    cout << "| " << left << setw(12) << "Balance";
//    cout << "\n_______________________________________________________";
//    cout << "_________________________________________\n" << endl;
//
//    double totalBalances = clsBankClient::getTotalBalances(); //calling static function 
//
//    if (vClients.size() == 0) {
//        cout << "\t\t\t\tNo Clients available in the system! ";
//    }
//    else {
//        for (clsBankClient client : vClients) {
//            printClientRecordBalanceLine(client);
//            cout << endl;
//        }
//    }
//
//    cout << "\n_______________________________________________________";
//    cout << "_________________________________________\n" << endl;
//    cout << "\t\t\t\t\t   Total Balances = " << totalBalances << endl;
//    cout << "\t\t\t\t\t   ( " << clsUtil::numberToText(totalBalances) << ")";
//}

int main() {
    
    clsMainScreen::showMainMenu();

    system("pause>0");
    return 0;
}