#include <iostream>
#include "clsLoginScreen.h"
#include "clsCurrency.h"

using namespace std;

static void _PrintCurrency(clsCurrency currency) {
	cout << "\nCurrency Card:\n";
	cout << "_____________________________\n";
	cout << "\nCountry    : " << currency.country();
	cout << "\nCode       : " << currency.currencyCode();
	cout << "\nName       : " << currency.currencyName();
	cout << "\nRate(1$) = : " << currency.rate();

	cout << "\n_____________________________\n";
}

int main() {

	/*while (true) {
		if (!clsLoginScreen::showLoginScreen()) {
			break;
		}
	}*/

	clsCurrency currency1 = currency1.findByCode("jod");

	if (currency1.isEmpty()) {
		cout << "\nCurrency Is Not Found!\n";
	}
	else {
		_PrintCurrency(currency1);
	}

	clsCurrency currency2 = currency2.findByCountry("Egypt");

	if (currency2.isEmpty()) {
		cout << "\nCurrency Is Not Found!\n";
	}
	else {
		_PrintCurrency(currency2);
	}

	cout << "Currency 1 after updating Rate:\n";
	currency1.updateRate(0.82);
	_PrintCurrency(currency1);
 
	system("pause>0");
	return 0;
}