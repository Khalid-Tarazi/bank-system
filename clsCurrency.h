#pragma once

#include<iostream>
#include<string>
#include "clsString.h"
#include <vector>
#include <fstream>

class clsCurrency {

private:

	enum enMode { emptyMode = 0, updateMode = 1};
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLinetoCurrencyObject(string line, string seperator = "#//#") {

		vector<string> vCurrencyData;
		vCurrencyData = clsString::split(line, seperator);

		return clsCurrency(enMode::updateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stod(vCurrencyData[3]));
	}

	static string _ConverCurrencyObjectToLine(clsCurrency currency, string seperator = "#//#") {

		string stCurrencyRecord = "";
		stCurrencyRecord += currency.country() + seperator;
		stCurrencyRecord += currency.currencyCode() + seperator;
		stCurrencyRecord += currency.currencyName() + seperator;
		stCurrencyRecord += to_string(currency.rate());

		return stCurrencyRecord;
	}

	static vector<clsCurrency> _LoadCurrencysDataFromFile() {

		vector <clsCurrency> vCurrencys;

		fstream myFile;
		myFile.open("Currencies.txt", ios::in);//read Mode

		if (myFile.is_open()) {
			
			string line;
			while (getline(myFile, line)) {
				clsCurrency currency = _ConvertLinetoCurrencyObject(line);

				vCurrencys.push_back(currency);
			}
			myFile.close();
		}
		return vCurrencys;
	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys) {

		fstream myFile;
		myFile.open("Currencies.txt", ios::out);//overwrite
		string dataLine;

		if (myFile.is_open()) {
			for (clsCurrency C : vCurrencys) {
				dataLine = _ConverCurrencyObjectToLine(C);
				myFile << dataLine << endl;
			}
			myFile.close();
		}
	}

	void _Update() {

		vector <clsCurrency> _vCurrencys;
		_vCurrencys = _LoadCurrencysDataFromFile();

		for (clsCurrency& C : _vCurrencys) {
			if (C.currencyCode() == currencyCode()) {
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(_vCurrencys);
	}

	static clsCurrency _GetEmptyCurrencyObject() {

		return clsCurrency(enMode::emptyMode, "", "", "", 0);
	}

public:

	 clsCurrency(enMode mode, string country, string currencyCode, string currencyName, float rate) {

		 _Mode = mode;
		 _Country = country;
		 _CurrencyCode = currencyCode;
		 _CurrencyName = currencyName;
		 _Rate = rate;
	 }

	 static vector<clsCurrency> getAllUSDRates() {

		 return _LoadCurrencysDataFromFile();
	 }

	 bool isEmpty() {

		 return (_Mode == enMode::emptyMode);
	 }

	 string country() {
		 return _Country;
	 }

	 string currencyCode() {
		 return _CurrencyCode;
	 }

	 string currencyName() {
		 return _CurrencyName;
	 }

	 void updateRate(float newRate) {
		 _Rate = newRate;
		 _Update();
	 }

	 float rate() {
		 return _Rate;
	 }

	 static clsCurrency findByCode(string currencyCode) {

		 currencyCode = clsString::upperAllString(currencyCode);

		 fstream myFile;
		 myFile.open("Currencies.txt", ios::in); // read mode

		 if (myFile.is_open()) {
			 
			 string line;
			 while (getline(myFile, line)) {
				 clsCurrency currency = _ConvertLinetoCurrencyObject(line);
				 if (currency.currencyCode() == currencyCode) {
					 myFile.close();
					 return currency;
				 }
			 }
			 myFile.close();
		 }
		 return _GetEmptyCurrencyObject();
	 }

	 static clsCurrency findByCountry(string country) {

		 country = clsString::upperAllString(country);

		 fstream myFile;
		 myFile.open("Currencies.txt", ios::in); // read mode

		 if (myFile.is_open()) {
			 
			 string line;
			 while (getline(myFile, line)) {
				 clsCurrency currency = _ConvertLinetoCurrencyObject(line);
				 if (clsString::upperAllString(currency.country()) == country) {
					 myFile.close();
					 return currency;
				 }
			 }
			 myFile.close();
		 }

		 return _GetEmptyCurrencyObject();
	 }

	 static bool isCurrencyExist(string currencyCode) {
		 clsCurrency C1 = clsCurrency::findByCode(currencyCode);
		 return (!C1.isEmpty());
	 }

	 static vector <clsCurrency> getCurrenciesList() {
		 return _LoadCurrencysDataFromFile();
	 }
};