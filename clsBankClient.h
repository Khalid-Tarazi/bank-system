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

	enum enMode { emptyMode = 0, updateMode = 1, addNewMode = 2};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;

	//private functions will be used here
	static clsBankClient _ConvertLineToClientObject(string line, string seperator = "#//#") {

		vector<string> vClientData;
		vClientData = clsString::split(line, seperator);

		return clsBankClient(enMode::updateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient client, string seperator = "#//#") {

		string stClientRecord = "";
		stClientRecord += client.firstName + seperator;
		stClientRecord += client.lastName + seperator;
		stClientRecord += client.email + seperator;
		stClientRecord += client.phone + seperator;
		stClientRecord += client.accountNumber() + seperator;
		stClientRecord += client.pinCode + seperator;
		stClientRecord += to_string(client.accountBalance);

		return stClientRecord;
	}

	static vector<clsBankClient> _LoadClientsDataFromFile() {

		vector<clsBankClient> vClients;

		fstream myFile;
		myFile.open("Clients.txt", ios::in); // read mode

		if (myFile.is_open()) {
			string line; 

			while(getline(myFile, line)) {
				clsBankClient client = _ConvertLineToClientObject(line);
				vClients.push_back(client);
			}
			myFile.close();
		}
		return vClients;
	}

	static void _SaveClientsDataToFile(vector <clsBankClient> vClients) {

		fstream myFile;
		myFile.open("Clients.txt", ios::out); // overwite mode

		string dataLine;

		if (myFile.is_open()) {
			
			for (clsBankClient C : vClients) {
				if (C.markedForDelete() == false) {
					//we only write records that are not marked for delete. 
					dataLine = _ConvertClientObjectToLine(C);
					myFile << dataLine << endl;
				}				
			}

			myFile.close();
		}
	}

	void _Update() {

		vector<clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients) {
			if (C.accountNumber() == accountNumber()) {
				C = *this; // the client we loaded = the updated info (*this)
				break;
			}
		}

		_SaveClientsDataToFile(_vClients);
	}

	void _AddNew() {
		
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string stDataLine) {
		fstream myFile;
		myFile.open("Clients.txt", ios::out | ios::app);

		if (myFile.is_open()) {
			myFile << stDataLine << endl;
			myFile.close();
		}
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

	bool markedForDelete() {
		return _MarkedForDelete;
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

	enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFailedAccountNumberExists = 2};

	enSaveResults save() {

		switch (_Mode) {
		case enMode::emptyMode: {
			return enSaveResults::svFailedEmptyObject;
			break;
		}
		case enMode::updateMode: {
			_Update();
			return enSaveResults::svSucceeded;
			break;
		}

		case enMode::addNewMode: {
			//This will add new record to file r database
			if (clsBankClient::isClientExist(_AccountNumber)) {
				return enSaveResults::svFailedAccountNumberExists;
			}
			else {
				_AddNew();
				//We need to set the mode to update after add new
				_Mode = enMode::updateMode;
				return enSaveResults::svSucceeded;
			}
			break;
		}
		}
	}

	static bool isClientExist(string accountNumber) {

		clsBankClient client1 = clsBankClient::find(accountNumber);

		return (!client1.isEmpty());
	}

	bool Delete() {

		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients) {
			if (C.accountNumber() == _AccountNumber) {
				C._MarkedForDelete = true;
				break;
			}
		}

		_SaveClientsDataToFile(_vClients);

		*this = _GetEmptyClientObject();

		return true;
	}

	static clsBankClient getAddNewClientObject(string accountNumber) {

		return clsBankClient(enMode::addNewMode, "", "", "", "", accountNumber, "", 0);
	}

	static vector<clsBankClient> getClientsList() {

		return _LoadClientsDataFromFile();
	}

	static double getTotalBalances() { //static - it involves all clients, you will not edit or update

		vector<clsBankClient> vClients = clsBankClient::getClientsList();

		double totalBalances = 0;

		for (clsBankClient client: vClients) {
			totalBalances += client.accountBalance;
		}

		return totalBalances;
	}
};

