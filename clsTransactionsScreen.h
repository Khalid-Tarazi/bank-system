#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;

class clsTransactionsScreen: protected clsScreen {

private:

    enum enTransactionsMenuOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eTransfer = 4, eTransferLogScreen = 5, eShowMainMenu = 6
    };
    
    static short readTransactionsMenuOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::readShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _ShowDepositScreen() {
        //cout << "\n Deposit Screen will be here.\n";
        clsDepositScreen::showDepositScreen();
    }

    static void _ShowWithdrawScreen() {
        //cout << "\n Withdraw Screen will be here.\n";
        clsWithdrawScreen::showWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen() {
        //cout << "\n Balances Screen will be here.\n";
        clsTotalBalancesScreen::showTotalBalances();
    }

    static void _ShowTransferScreen() {
        
        clsTransferScreen::showTransferScreen();
    }

    static void _ShowTransferLogScreen() {

        clsTransferLogScreen::showTransferLogScreen();
    }

    static void _GoBackToTransactionsMenu() {
        cout << "\n\nPress any key to go back to Transactions Menu...";
        system("pause>0");
        showTransactionsMenu();
    }

    static void _PerformTransactionsMenuOption(enTransactionsMenuOptions transactionsMenuOptions) {

        switch (transactionsMenuOptions) {
            
        case enTransactionsMenuOptions::eDeposit: {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenuOptions::eWithdraw: {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenu();
            break;
        }
        
        case enTransactionsMenuOptions::eShowTotalBalance: {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenuOptions::eTransfer: {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenuOptions:: eTransferLogScreen: {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenu();
            break;
        }
        
        case enTransactionsMenuOptions::eShowMainMenu: {
            //do nothing here the main screen will handle it :-) ;
        }
        }
    }

public:

	static void showTransactionsMenu() {

        if (!checkAccessRights(clsUser::enPermissions::pAddNewClient)) {
            return;// this will exit the function and it will not continue
        }

		system("cls");
		_DrawScreenHeader("\t Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenuOption((enTransactionsMenuOptions)readTransactionsMenuOption());
	}
};