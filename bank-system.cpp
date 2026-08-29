#include <iostream>
#include "clsLoginScreen.h"

using namespace std;

int main() {

	while (true) {
		if (!clsLoginScreen::showLoginScreen()) {
			break;
		}
	}
 
	system("pause>0");
	return 0;
}