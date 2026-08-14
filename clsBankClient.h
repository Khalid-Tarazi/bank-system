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

	//private functions will be used here
	static clsBankClient _ConvertLineToClientObject(string line, string seperator = "#//#") {

		vector<string> vClientData;
		vClientData = clsString::split(line, seperator);

		return clsBankClient(enMode::updateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static clsBankClient _GetEmptyClientObject() {

		return clsBankClient(enMode::emptyMode, "", "", "", "", "", "", 0);
	}

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

		fstream myFile;
		myFile.open("Clients.txt", ios::in); // read mode

		if (myFile.is_open()) {

			string line;
			while(getline(myFile, line)) {

				clsBankClient client = _ConvertLineToClientObject(line);
				if (client.accountNumber() == accountNumber) {
					myFile.close();
					return client;
				}
				vClients.push_back(client);
			}
			myFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient find(string accountNumber, string pinCode) {

		vector<clsBankClient> vClients; // structure and it's type the class itself

		fstream myFile;
		myFile.open("Clients.txt", ios::in); // read mode

		if (myFile.is_open()) {

			string line;
			while (getline(myFile, line)) {

				clsBankClient client = _ConvertLineToClientObject(line);
				if (client.accountNumber() == accountNumber && client.pinCode == pinCode) { // difference is here only
					myFile.close();
					return client;
				}
				vClients.push_back(client);
			}
			myFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool isClientExist(string accountNumber) {

		clsBankClient client1 = clsBankClient::find(accountNumber);

		return (!client1.isEmpty());
	}






};

