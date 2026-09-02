#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyRateScreen : protected clsScreen {

private:


	static float _ReadRate() {

		cout << "\nEnter new rate: ";
		float newRate = 0;

		newRate = clsInputValidate::readFloatNumber();
		return newRate;
	}

	static void _PrintCurrency(clsCurrency currency) {
		
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << currency.country();
		cout << "\nCode       : " << currency.currencyCode();
		cout << "\nName       : " << currency.currencyName();
		cout << "\nRate(1$) = : " << currency.rate();

		cout << "\n_____________________________\n";
	}

public:

	static void showUpdateCurrencyRateScreen() {

		_DrawScreenHeader("\tUpdate Currency Screen");

		string currencyCode = "";

		cout << "\nPlease enter your currency code: ";
		currencyCode = clsInputValidate::readString();

		while (!clsCurrency::isCurrencyExist(currencyCode)) {
			cout << "\nCurrency is not found, choose another one: ";
			currencyCode = clsInputValidate::readString();
		}

		clsCurrency currency = clsCurrency::findByCode(currencyCode);
		_PrintCurrency(currency);
		
		cout << "\nAre you sure you want to update the rate of this Currency y/n? ";

		char answer = 'n';
		cin >> answer;

		if (answer == 'Y' || answer == 'y') {
			cout << "\n\nUpdate Currency Rate:";
			cout << "\n____________________\n";

			currency.updateRate(_ReadRate());
			cout << "\nCurrency Rate Updated Successfully. \n";
			_PrintCurrency(currency);
		}
	}
};

