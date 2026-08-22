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

void addNewClient() {

    string accountNumber = "";

    cout << "\nPlease enter account number: ";
    accountNumber = clsInputValidate::readString();
    while (clsBankClient::isClientExist(accountNumber)) {

        cout << "\nAccount number is already used, choose another one: ";
        accountNumber = clsInputValidate::readString();
    }

    clsBankClient newClient = clsBankClient::getAddNewClientObject(accountNumber);
        
    readClientInfo(newClient);

    clsBankClient::enSaveResults saveResult;

    saveResult = newClient.save(); // added new mode

    switch (saveResult) {

    case clsBankClient::enSaveResults::svSucceeded: {
        cout << "\nAccount added successfully\n";
        newClient.print();
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

void deleteClient() { // return true or false, and return empty object, and it deletes from file.
    
    string accountNumber = "";

    cout << "\nPlease enter account number: ";
    accountNumber = clsInputValidate::readString();
    while (!clsBankClient::isClientExist(accountNumber)) {
        cout << "\nAccount is not found, choose another one: ";
        accountNumber = clsInputValidate::readString();
    }

    clsBankClient client1 = clsBankClient::find(accountNumber);
    client1.print();

    cout << "\nAre you sure you want to delete this client? y/n ";

    char answer = 'n';
    cin >> answer;

    if (answer == 'y' || answer == 'Y') {
        if (client1.Delete()) {  // I have to rename to Delete, or else I will get conflict with delete() bulit in function
            cout << "\nClient deleted successfully\n";
            client1.print(); // to show the object
        }
        else {
            cout << "\nError client was not deleted\n";
        }
    }
}

int main() {
    
    deleteClient();

    system("pause>0");
    return 0;
}