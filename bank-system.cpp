#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
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

void printClientRecordLine(clsBankClient Client) {

    cout << "| " << setw(15) << left << Client.accountNumber();
    cout << "| " << setw(20) << left << Client.fullName();
    cout << "| " << setw(12) << left << Client.phone;
    cout << "| " << setw(20) << left << Client.email;
    cout << "| " << setw(10) << left << Client.pinCode;
    cout << "| " << setw(12) << left << Client.accountBalance;
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

void showClientsList() {

    vector<clsBankClient> vClients = clsBankClient::getClientsList();

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else 
        for (clsBankClient client : vClients) {
            printClientRecordLine(client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

int main() {
    
    showClientsList();

    system("pause>0");
    return 0;
}