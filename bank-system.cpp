#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

void readClientInfo(clsBankClient& client) {

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

void updateClient() {

    string accountNumber = "";

    cout << "\nPlease enter account number: ";
    accountNumber = clsInputValidate::readString();

    while (!clsBankClient::isClientExist(accountNumber)) {
        cout << "\nPlease enter account number: ";
        accountNumber = clsInputValidate::readString();
    }

    clsBankClient client1 = clsBankClient::find(accountNumber);
    client1.print();

    cout << "\n\nUpdate client info:";
    cout << "\n_____________________\n";

    readClientInfo(client1);

    clsBankClient::enSaveResults saveResult;

    saveResult = client1.save();

    switch (saveResult) {

    case clsBankClient::svSucceeded: {
        cout << "\nAccount updated successfully\n";
        client1.print();
        break;
    }
    case clsBankClient::svFailedEmptyObject: {
        cout << "\nError account was not saved because it's empty";
        break;
    }
    }





}

int main() {
     
    updateClient();

    system("pause>0");
    return 0;
}