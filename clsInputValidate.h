#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"

class clsInputValidate {

public:

	static bool isNumberBetween(short number, short from, short to) {

		if (number >= from && number <= to)
			return true;
		else
			return false;
	}

	static bool isNumberBetween(int number, int from, int to) {

		if (number >= from && number <= to)
			return true;
		else
			return false;
	}

	static bool isNumberBetween(double number, double from, double to) {

		if (number >= from && number <= to)
			return true;
		else
			return false;
	}

	static bool isDateBetween(clsDate date, clsDate from, clsDate to) {
		//Date>=From && Date<=To
		if ((clsDate::isDate1AfterDate2(date, from) || clsDate::isDate1EqualsDate2(date, from))
			&&
			(clsDate::isDate1BeforeDate2(date, to) || clsDate::isDate1EqualsDate2(date, to))) {
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::isDate1AfterDate2(date, to) || clsDate::isDate1EqualsDate2(date, to))
			&&
			(clsDate::isDate1BeforeDate2(date, from) || clsDate::isDate1EqualsDate2(date, from))) {
			return true;
		}

		return false;
	}

	static int readIntNumber(string errorMessage = "Invalid number, enter again\n") {

		int number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errorMessage;
		}
		return number;
	}

	static int readIntNumberBetween(int from, int to, string errorMessage = "Number is not within range, Enter again:\n") {
		int number = readIntNumber();

		while (!isNumberBetween(number, from, to)) {
			cout << errorMessage;
			number = readIntNumber();
		}
		return number;
	}

	static double readFloatNumber(string errorMessage = "Invalid Number, Enter again\n") {
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errorMessage;
		}
		return Number;
	}

	static double readFloatNumberBetween(double from, double to, string errorMessage = "Number is not within range, Enter again:\n") {
		float Number = readFloatNumber();

		while (!isNumberBetween(Number, from, to)) {
			cout << errorMessage;
			Number = readDblNumber();
		}
		return Number;
	}


	static double readDblNumber(string errorMessage = "Invalid Number, Enter again\n") {
		double number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errorMessage;
		}
		return number;
	}

	static double readDblNumberBetween(double from, double to, string errorMessage = "Number is not within range, Enter again:\n") {
		double number = readDblNumber();

		while (!isNumberBetween(number, from, to)) {
			cout << errorMessage;
			number = readDblNumber();
		}
		return number;
	}

	static bool isValidDate(clsDate date) {
		return clsDate::isValidDate(date);
	}

	static string readString() {
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}

};