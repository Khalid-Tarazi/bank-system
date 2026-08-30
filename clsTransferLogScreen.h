#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"

class clsTransferLogScreen: protected clsScreen {

private:

    static void printTransferLogRecordLine(clsBankClient::stTransferLogRecord transferLogRecord) {

        cout << setw(8) << left << "" << "| " << setw(23) << left << transferLogRecord.dateTime;
        cout << "| " << setw(8) << left << transferLogRecord.sourceAccountNumber;
        cout << "| " << setw(8) << left << transferLogRecord.destinationAccountNumber;
        cout << "| " << setw(8) << left << transferLogRecord.amount;
        cout << "| " << setw(10) << left << transferLogRecord.srcBalanceAfter;
        cout << "| " << setw(10) << left << transferLogRecord.destBalanceAfter;
        cout << "| " << setw(8) << left << transferLogRecord.userName;
    }

public:

	static void showTransferLogScreen() {

        vector<clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::getTransferLogList();

        string title = "\tTransfer Log List Screen";
        string subTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(title, subTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord record : vTransferLogRecord) {

                printTransferLogRecordLine(record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
	}
};

