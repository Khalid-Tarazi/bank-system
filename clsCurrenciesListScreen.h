#pragma once
#include <ioStream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>

class clsCurrenciesListScreen:protected clsScreen {

private:

	static void printCurrencyRecordLine(clsCurrency currency) {

		cout << setw(8) << left << "" << "| " << setw(30) << left << currency.country();
		cout << "| " << setw(8) << left << currency.currencyCode();
		cout << "| " << setw(45) << left << currency.currencyName();
		cout << "| " << setw(10) << left << currency.rate();
	}

public:

	static void showCurrenciesListScreen() {

		vector<clsCurrency> vCurrencies = clsCurrency::getCurrenciesList();
		string title = "\t Currencies List Screen";
		string subTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency.";

		_DrawScreenHeader(title, subTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		if (vCurrencies.size() == 0) {
			cout << "\t\t\t\tNo currencies available in the system!";
		}
		else {
			for (clsCurrency currency : vCurrencies) {
				printCurrencyRecordLine(currency);
				cout << endl;
			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
	}
};