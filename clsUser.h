#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsDate.h"
#include "clsUtil.h"

using namespace std;

class clsUser: public clsPerson {

private:

	enum enMode { emptyMode = 0, updateMode = 1, addNewMode = 2};

	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;

	bool _MarkedForDelete = false;

	struct stLoginRegisterRecord;

	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string line, string seperator = "#//#") {
		
		stLoginRegisterRecord loginRegisterRecord;

		vector <string> loginRegisterDataLine = clsString::split(line, seperator);
		loginRegisterRecord.dateTime = loginRegisterDataLine[0];
		loginRegisterRecord.userName = loginRegisterDataLine[1];
		loginRegisterRecord.password = loginRegisterDataLine[2];
		loginRegisterRecord.permissions = stoi(loginRegisterDataLine[3]);

		return loginRegisterRecord;
	}

	string _PrepareLogInRecord(string seperator = "#//#") {
		string loginRecord = "";
		loginRecord += clsDate::getSystemDateTimeString() + seperator;
		loginRecord += userName + seperator;
		//here we encrypt and store the encrypted Password not the real one.
		loginRecord += clsUtil::encryptText(password) + seperator;
		loginRecord += to_string(permissions);
		return loginRecord;
	}

	static clsUser _ConvertLineToUserObject(string line, string seperator = "#//#") {

		vector<string> vUserData;
		vUserData = clsString::split(line, seperator);

		return clsUser(enMode::updateMode, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], clsUtil::decryptText(vUserData[5]), stoi(vUserData[6]));
	}

	static string _ConvertUserObjectToLine(clsUser user, string seperator = "#//#") {

		string userRecord = "";
		userRecord += user.firstName + seperator;
		userRecord += user.lastName + seperator;
		userRecord += user.email + seperator;
		userRecord += user.phone + seperator;
		userRecord += user.userName + seperator;
		//here we encrypt and store the encrypted Password not the real one.
		userRecord += clsUtil::encryptText(user.password) + seperator;
		userRecord += to_string(user.permissions);

		return userRecord;
	}

	static vector<clsUser> _LoadUsersDataFromFile() {

		vector<clsUser> vUsers;

		fstream myFile;
		myFile.open("Users.txt", ios::in);//read Mode

		if (myFile.is_open()) {

			string Line;

			while (getline(myFile, Line)) {

				clsUser User = _ConvertLineToUserObject(Line);

				vUsers.push_back(User);
			}
			myFile.close();

		}

		return vUsers;
	}

	static void _SaveUsersDataToFile(vector <clsUser> vUsers) {

		fstream myFile;
		myFile.open("Users.txt", ios::out);//overwrite

		string DataLine;

		if (myFile.is_open()) {

			for (clsUser U : vUsers) {
				if (U.markedForDelete() == false) {
					//we only write records that are not marked for delete.  
					DataLine = _ConvertUserObjectToLine(U);
					myFile << DataLine << endl;
				}
			}
			myFile.close();
		}
	}

	void _Update() {
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : _vUsers) {
			if (U.userName == _UserName) {
				U = *this;
				break;
			}
		}
		_SaveUsersDataToFile(_vUsers);
	}

	void _AddNew() {

		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	void _AddDataLineToFile(string  stDataLine) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open()) {
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	static clsUser _GetEmptyUserObject() {
		return clsUser(enMode::emptyMode, "", "", "", "", "", "", 0);
	}

public:

	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64, 
		pShowLogInRegister = 128 
	};

	struct stLoginRegisterRecord {
		string dateTime;
		string userName;
		string password;
		int permissions;
	};


	clsUser(enMode mode, string firstName, string lastName, string email, string phone, string userName, string password, 
		int permissions) : clsPerson(firstName, lastName, email, phone) {

		_Mode = mode;
		_UserName = userName;
		_Password = password;
		_Permissions = permissions;
	}

	bool isEmpty() {
		return (_Mode == enMode::emptyMode);
	}

	bool markedForDelete() {
		return _MarkedForDelete;
	}

	void setUserName(string userName) {
		_UserName = userName;
	}

	string getUserName() {
		return _UserName;
	}

	__declspec(property(get = getUserName, put = setUserName)) string userName;

	void setPassword(string password) {
		_Password = password;
	}

	string getPassword() {
		return _Password;
	}

	__declspec(property(get = getPassword, put = setPassword)) string password;

	void setPermissions(int permissions) {
		_Permissions = permissions;
	}

	int getPermissions() {
		return _Permissions;
	}

	__declspec(property(get = getPermissions, put = setPermissions)) int permissions;

	static clsUser find(string userName) {

		fstream myFile;
		myFile.open("Users.txt", ios::in); // read mode

		if (myFile.is_open()) {
			string line;

			while (getline(myFile, line)) {
				clsUser user = _ConvertLineToUserObject(line);

				if (user.userName == userName) {
					myFile.close();
					return user;
				}
			}

			myFile.close();
		}

		return _GetEmptyUserObject();
	}

	static clsUser find(string userName, string password) {

		fstream myFile;
		myFile.open("Users.txt", ios::in); // read mode

		if (myFile.is_open()) {
			string line;

			while (getline(myFile, line)) {
				clsUser user = _ConvertLineToUserObject(line);

				if (user.userName == userName && user.password == password) {
					myFile.close();
					return user;
				}
			}

			myFile.close();
		}

		return _GetEmptyUserObject();
	}

	enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFailedUserExists = 2};

	enSaveResults save() {

		switch (_Mode) {
		
		case enMode::emptyMode: {
			if (isEmpty())
				return enSaveResults::svFailedEmptyObject;
		}

		case enMode::updateMode: {
			_Update();
			return enSaveResults::svSucceeded;
			break;
		}
		case enMode::addNewMode: {
			//this will add new record to file or database
			if (clsUser::isUserExist(_UserName)) {
				return enSaveResults::svFailedUserExists;
			}
			else {
				_AddNew();
				//we need to set the mode to update after add new
				_Mode = enMode::updateMode;
				return enSaveResults::svSucceeded;
			}
			break;
		}
		}
	}

	static bool isUserExist(string userName) {
		
		clsUser user = clsUser::find(userName);
		return !user.isEmpty();
	}

	bool Delete() {

		vector<clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : _vUsers) {
			if (U.userName == _UserName) {
				U._MarkedForDelete = true;
				break;
			}
		}

		_SaveUsersDataToFile(_vUsers);

		*this = _GetEmptyUserObject();
		return true;
	}

	static clsUser getAddNewUserObject(string userName) {

		return clsUser(enMode::addNewMode, "", "", "", "", userName, "", 0);
	}

	static vector<clsUser> getUsersList() {

		return _LoadUsersDataFromFile();
	}

	bool checkAccessPermission(enPermissions permission) {

		if (this->permissions == enPermissions::eAll) return true;

		if ((permission & this->permissions) == permission) { //bitwise - bit &
			return true;
		}
		else {
			return false;
		}
	}

	void registerLogIn() {

		string stDataLine = _PrepareLogInRecord();

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open()) {

			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}
	
	static  vector <stLoginRegisterRecord> getLoginRegisterList() {
		
		vector <stLoginRegisterRecord> vLoginRegisterRecord;

		fstream myFile;
		myFile.open("LoginRegister.txt", ios::in);//read Mode

		if (myFile.is_open()) {

			string line;

			stLoginRegisterRecord loginRegisterRecord;

			while (getline(myFile, line)) {

				loginRegisterRecord = _ConvertLoginRegisterLineToRecord(line);

				vLoginRegisterRecord.push_back(loginRegisterRecord);
			}
			myFile.close();
		}

		return vLoginRegisterRecord;
	}
};