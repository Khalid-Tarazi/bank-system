#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"

using namespace std;

class clsTransactionsScreen: protected clsScreen {

private:

    enum enTransactionsMenuOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eShowMainMenu = 4
    };
    
    static short readTransactionsMenuOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        short Choice = clsInputValidate::readShortNumberBetween(1, 4, "Enter Number between 1 to 4? ");
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
        cout << "\n Balances Screen will be here.\n";
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
        

        case enTransactionsMenuOptions::eShowMainMenu: {
            //do nothing here the main screen will handle it :-) ;
        }
        }
    }

public:

	static void showTransactionsMenu() {

		system("cls");
		_DrawScreenHeader("\t Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenuOption((enTransactionsMenuOptions)readTransactionsMenuOption());
	}
};