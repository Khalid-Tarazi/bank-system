#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen:protected clsScreen {

private:

    static void _PrintCurrency(clsCurrency currency) {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << currency.country();
        cout << "\nCode       : " << currency.currencyCode();
        cout << "\nName       : " << currency.currencyName();
        cout << "\nRate(1$) = : " << currency.rate();

        cout << "\n_____________________________\n";
    }

    static void _ShowResults(clsCurrency currency) {
        
        if (!currency.isEmpty()) {
            cout << "\nCurrency Found\n";
            _PrintCurrency(currency);
        }
        else {
            cout << "\nCurrency Was not Found\n";
        }
    }

public:


	static void showFindCurrencyScreen() {

        _DrawScreenHeader("\t  Find Currency Screen");

        cout << "\nFind By: [1] Code or [2] Country ? ";
        
        short answer = 1;
        cin >> answer;

        if (answer == 1) {
            string currencyCode;
            cout << "\nPlease Enter Currency Code: ";
            currencyCode = clsInputValidate::readString();

            clsCurrency currency = clsCurrency::findByCode(currencyCode);
            _ShowResults(currency);
        }
        else {
            string country;
            cout << "\nPlease Enter Country Name: ";
            country = clsInputValidate::readString();
            clsCurrency currency = clsCurrency::findByCountry(country);
            _ShowResults(currency);
        }
	}
};

