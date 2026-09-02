#pragma once

#include <iostream>
#include "clsScreen.h"



class clsCurrencyCalculatorScreen: protected clsScreen {

private:

	static float _ReadAmount() {

		cout << "\n Enter amount to exchange: ";
		float amount = 0;

		amount = clsInputValidate::readFloatNumber();
		return amount;
	}

	static clsCurrency _GetCurrency(string message) { // just for organizing

		string currencyCode;
		cout << message << endl;

		currencyCode = clsInputValidate::readString();

		while (!clsCurrency::isCurrencyExist(currencyCode)) {
			cout << "\nCurrency is not found, choose another one: ";
			currencyCode = clsInputValidate::readString();
		}

		clsCurrency currency = clsCurrency::findByCode(currencyCode);
		return currency;
	}

	static  void _PrintCurrencyCard(clsCurrency currency, string title = "Currency Card:") {

		cout << "\n" << title << "\n";
		cout << "_____________________________\n";
		cout << "\nCountry       : " << currency.country();
		cout << "\nCode          : " << currency.currencyCode();
		cout << "\nName          : " << currency.currencyName();
		cout << "\nRate(1$) =    : " << currency.rate();
		cout << "\n_____________________________\n\n";
	}

	static void _PrintCalculationsResults(float amount, clsCurrency currency1, clsCurrency currency2) {

		_PrintCurrencyCard(currency1, "Convert From: ");

		float amountInUSD = currency1.convertToUSD(amount);

		cout << amount << " " << currency1.currencyCode()
			<< " = " << amountInUSD << " USD\n";
		
		if (currency2.currencyCode() == "USD") {
			return; //exit the function and don't continue below
		}

		cout << "\nConverting from USD to:\n";
		_PrintCurrencyCard(currency2, "To: ");

		float amountInCurrency2 = currency1.convertToOtherCurrency(amount, currency2);
		cout << amount << " " << currency1.currencyCode()
			<< " = " << amountInCurrency2 << " " << currency2.currencyCode();
	}

public:

	static void showCurrencyCalculatorScreen() {

		char Continue = 'Y';

		while (Continue == 'Y' || Continue == 'y') {

			system("cls");
			_DrawScreenHeader("\t Currency Calculator");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");
			float Amount = _ReadAmount();

			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want to perform another calculation? y/n ? ";
			cin >> Continue;
		}
	}
};

