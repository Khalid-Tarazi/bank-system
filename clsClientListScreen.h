#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h" //import it so we can call the object and call the client list from it
#include <iomanip>

class clsClientListScreen: protected clsScreen {

private:

    static void _PrintClientRecordLine(clsBankClient client) {

        cout << setw(8) << left << "" << "| " << setw(15) << left << client.accountNumber();
        cout << "| " << setw(20) << left << client.fullName();
        cout << "| " << setw(12) << left << client.phone;
        cout << "| " << setw(20) << left << client.email;
        cout << "| " << setw(10) << left << client.pinCode;
        cout << "| " << setw(12) << left << client.accountBalance;
    }
	
public:

	static void showClientsList() { //same function I used before, but with minimum editing

        if (!checkAccessRights(clsUser::enPermissions::pAddNewClient)) {
            return;// this will exit the function and it will not continue
        }

        vector<clsBankClient> vClients = clsBankClient::getClientsList();

        string title = "\tClient List Screen";
        string subTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(title, subTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else
            for (clsBankClient client : vClients) {
                _PrintClientRecordLine(client);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
	}
};

