#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
using namespace std;

class clsBankClient : public clsPerson {

private:

	enum enMode { emptyMode = 0, updateMode = 1};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;


public:

	clsBankClient(enMode mode, string firstName, string lastName, string email, string phone, 
		string accountNumber, string pinCode, float accountBalance) : clsPerson(firstName, lastName, email, phone) {
		
		_Mode = mode;
		_AccountNumber = accountNumber;
		_PinCode = pinCode;
		_AccountBalance = accountBalance;
	}

	bool isEmpty() {	//to check the mode is empty or not

		return (_Mode == enMode::emptyMode);
	}

	string accountNumber() { // read only property, no one is allowed to edit it
		
		return _AccountNumber;
	}

	void setPinCode(string pinCode) {
		
		_PinCode = pinCode;
	}

	string getPinCode() {

		return _PinCode;
	}

	__declspec(property(get = getPinCode, put = setPinCode)) string pinCode;

	void setAccountBalance(float accountBalance) {

		_AccountBalance = accountBalance;
	}

	float getAccountBalance() {

		return _AccountBalance;
	}

	__declspec(property(get = getAccountBalance, put = setAccountBalance)) float accountBalance;

	void print() {

		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << firstName;
		cout << "\nLastName    : " << lastName;
		cout << "\nFull Name   : " << fullName();
		cout << "\nEmail       : " << email;
		cout << "\nPhone       : " << phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";
	}

	static clsBankClient find(string accountNumber) {
		
		vector<clsBankClient> vClients; // structure and it's type the class itself

	}

	static clsBankClient find(string accountNumber, string pinCode) {

	}








};

