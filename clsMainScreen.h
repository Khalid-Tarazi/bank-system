#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include <iomanip>

using namespace std;

class clsMainScreen: protected clsScreen {

private:
	
	enum enMainMenuOptions { 
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6,
		eManageUsers = 7, eExit = 8
	};

	static short _ReadMainMenuOption() {

		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
		short choice = clsInputValidate::readShortNumberBetween(1, 8, "Enter Number between 1 to 8? ");
		return choice;
	}

	static void _GoBackToMainMenu() {
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";

		system("pause>0");
		showMainMenu();
	}

	static void _ShowAllClientsScreen() {
		//cout << "\nClient List Screen Will be here...\n";
		clsClientListScreen::showClientsList();
	}

	static void _ShowAddNewClientsScreen() {
		//cout << "\nAdd New Client Screen Will be here...\n";
		clsAddNewClientScreen::showAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen() {
		//cout << "\nDelete Client Screen Will be here...\n";
		clsDeleteClientScreen::showDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen() {
		//cout << "\nUpdate Client Screen Will be here...\n";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen() {
		cout << "\nFind Client Screen Will be here...\n";
	}

	static void _ShowTransactionsMenu() {
		cout << "\nTransactions Menu Will be here...\n";

	}

	static void _ShowManageUsersMenu() {
		cout << "\nUsers Menu Will be here...\n";

	}

	static void _ShowEndScreen() {
		cout << "\nEnd Screen Will be here...\n";

	}

	static void _PerformMainMenuOptions(enMainMenuOptions mainMenuOption) {

		switch (mainMenuOption) {
		
		case enMainMenuOptions::eListClients: {
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;
		}

		case enMainMenuOptions::eAddNewClient: {
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenu();
			break;
		}

		case enMainMenuOptions::eDeleteClient: {
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		}

		case enMainMenuOptions::eUpdateClient: {
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		}
		
		case enMainMenuOptions::eFindClient: {
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;
		}

		case enMainMenuOptions::eShowTransactionsMenu: {
			system("cls");
			_ShowTransactionsMenu();
			break;
		}

		case enMainMenuOptions::eManageUsers: {
			system("cls");
			_ShowManageUsersMenu();
			break;
		}

		case enMainMenuOptions::eExit: {
			system("cls");
			_ShowEndScreen();
			//Login();
			break;
		}
		}
	}

public:

	static void showMainMenu() {

		system("cls");
		_DrawScreenHeader("\t\tMain Menu");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Clients List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformMainMenuOptions((enMainMenuOptions)_ReadMainMenuOption());
	}
};