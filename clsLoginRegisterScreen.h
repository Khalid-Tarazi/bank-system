#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsUser.h"


class clsLoginRegisterScreen: protected clsScreen {

private:

    static void printLoginRegisterRecordLine(clsUser::stLoginRegisterRecord loginRegisterRecord) {

        cout << setw(8) << left << "" << "| " << setw(35) << left << loginRegisterRecord.dateTime;
        cout << "| " << setw(20) << left << loginRegisterRecord.userName;
        cout << "| " << setw(20) << left << loginRegisterRecord.password;
        cout << "| " << setw(10) << left << loginRegisterRecord.permissions;
    }


public:

	static void ShowLoginRegisterScreen() {

        if (!checkAccessRights(clsUser::enPermissions::pShowLogInRegister)) {
            return; // this will exit the function and it will not continue
        }

        vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::getLoginRegisterList();

        string title = "\tLogin Register List Screen";
        string subTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

        _DrawScreenHeader(title, subTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord record : vLoginRegisterRecord)
            {

                printLoginRegisterRecordLine(record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
	}

};

