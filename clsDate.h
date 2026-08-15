#pragma warning(disable : 4996)
#pragma once

#include <iostream>
#include <string>
#include "clsString.h"

using namespace std;

class clsDate {

private:

	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

public:

	clsDate() {

		time_t t = time(0);
		tm* now = localtime(&t);
		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}

	clsDate(string sDate) {

		vector <string> vDate;
		vDate = clsString::split(sDate, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}

	clsDate(short day, short month, short year) {

		_Day = day;
		_Month = month;
		_Year = year;
	}

	clsDate(short dateOrderInYear, short year) {

		//This will construct a date by date order in year
		clsDate date1 = getDateFromDayOrderInYear(dateOrderInYear, year);
		_Day = date1.day;
		_Month = date1.month;
		_Year = date1.year;
	}

	void setDay(short day) {
		_Day = day;
	}

	short getDay() {
		return _Day;
	}

	__declspec(property(get = getDay, put = setDay)) short day;

	void setMonth(short month) {
		_Month = month;
	}

	short getMonth() {
		return _Month;
	}

	__declspec(property(get = getMonth, put = setMonth)) short month;

	void setYear(short year) {
		_Year = year;
	}

	short getYear() {
		return _Year;
	}

	__declspec(property(get = getYear, put = setYear)) short year;

	void print() {
		cout << dateToString() << endl;
	}

	static clsDate getSystemDate() {

		time_t t = time(0);
		tm* now = localtime(&t);
		short day, month, year;

		year = now->tm_year + 1900;
		month = now->tm_mon + 1;
		day = now->tm_mday;

		return clsDate(day, month, year);
	}

	static bool isValidDate(clsDate Date) {
		if (Date.day < 1 || Date.day>31)
			return false;
		if (Date.month < 1 || Date.month>12)
			return false;

		if (Date.month == 2) {
			if (isLeapYear(Date.year)) {
				if (Date.day > 29)
					return false;
			}
			else {
				if (Date.day > 28)
					return false;
			}
		}

		short daysInMonth = numberOfDaysInMonth(Date.month,
			Date.year);
		if (Date.day > daysInMonth)
			return false;
		return true;
	}

	bool isValid() {
		return isValidDate(*this);
	}

	static string dateToString(clsDate Date) {
		return to_string(Date.day) + "/" + to_string(Date.month) +
			"/" + to_string(Date.year);
	}

	string dateToString() {
		return dateToString(*this);
	}

	static bool isLeapYear(short year) {

		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	bool isLeapYear() {
		return isLeapYear(_Year);
	}

	static short numberOfDaysInYear(short year) {
		return isLeapYear(year) ? 366 : 365;
	}

	short numberOfDaysInYear() {
		return numberOfDaysInYear(_Year);
	}

	static short numberOfHoursInYear(short year) {
		return numberOfDaysInYear(year) * 24;
	}

	short numberOfHoursInYear() {
		return numberOfHoursInYear(_Year);
	}

	static int numberOfMinutesInYear(short year) {
		return numberOfHoursInYear(year) * 60;
	}

	int numberOfMinutesInYear() {
		return numberOfMinutesInYear(_Year);
	}

	static int numberOfSecondsInYear(short year) {
		return numberOfMinutesInYear(year) * 60;
	}

	int numberOfSecondsInYear() {
		return numberOfSecondsInYear(_Year);
	}

	static short numberOfDaysInMonth(short month, short year) {
		if (month < 1 || month > 12) return 0;

		int numberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		return  (month == 2) ? (isLeapYear(year) ? 29 : 28) : numberOfDays[month - 1]; //ternary inside ternary opearator
	}

	short numberOfDaysInMonth() {
		return numberOfDaysInMonth(_Month, _Year);
	}

	static short numberOfHoursInMonth(short month, short year) {
		return numberOfDaysInMonth(month, year) * 24;
	}

	short numberOfHoursInMonth() {
		return numberOfHoursInMonth(_Month, _Year);
	}

	static int numberOfMinutesInMonth(short month, short year) {
		return numberOfHoursInMonth(month, year) * 60;
	}

	int numberOfMinutesInMonth() {
		return numberOfMinutesInMonth(_Month, _Year);
	}

	static int numberOfSecondsInMonth(short month, short year) {
		return numberOfMinutesInMonth(month, year) * 60;
	}

	int numberOfSecondsInMonth() {
		return numberOfSecondsInMonth(_Month, _Year);
	}

	static short dayOfWeekOrder(short Day, short Month, short Year) {
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;
		// Gregorian:
		//0:sun, 1:Mon, 2:Tue...etc
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short dayOfWeekOrder() {
		return dayOfWeekOrder(_Day, _Month, _Year);
	}

	static string dayShortName(short DayOfWeekOrder) {
		string arrDayNames[] = {
		"Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[DayOfWeekOrder];
	}

	static string dayShortName(short day, short month, short year) {
		string arrDayNames[] = {
		"Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[dayOfWeekOrder(day, month, year)];
	}

	string  dayShortName() {
		string arrDayNames[] = {
		"Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[dayOfWeekOrder(day, month, year)];
	}

	static string monthShortName(short MonthNumber) {
		string Months[12] = { "Jan", "Feb", "Mar",
		"Apr", "May", "Jun",
		"Jul", "Aug", "Sep",
		"Oct", "Nov", "Dec"
		};
		return (Months[MonthNumber - 1]);
	}

	string monthShortName() {
		return monthShortName(_Month);
	}

	static void printMonthCalendar(short Month, short Year) {
		int NumberOfDays;
		// Index of the day from 0 to 6
		int current = dayOfWeekOrder(1, Month, Year);
		NumberOfDays = numberOfDaysInMonth(Month, Year);
		// Print the current month name
		printf("\n _______________%s_______________\n\n",
			monthShortName(Month).c_str());
		// Print the columns
		printf(" Sun Mon Tue Wed Thu Fri Sat\n");
		// Print appropriate spaces
		int i;
		for (i = 0; i < current; i++)
			printf(" ");
		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);
			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		printf("\n _________________________________\n");
	}

	void printMonthCalendar() {
		printMonthCalendar(_Month, _Year);
	}

	static void printYearCalendar(int Year) {
		printf("\n _________________________________\n\n");
		printf("      Calendar - %d\n", Year);
		printf(" _________________________________\n");
		for (int i = 1; i <= 12; i++)
		{
			printMonthCalendar(i, Year);
		}
		return;
	}

	void printYearCalendar() {
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", _Year);
		printf("  _________________________________\n");


		for (int i = 1; i <= 12; i++)
		{
			printMonthCalendar(i, _Year);
		}

		return;
	}

	static int numberOfDaysFromTheBeginingOfTheYear(short day, short month, short year) {

		int totalDays = 0;

		for (int i = 1; i <= month - 1; i++) {
			totalDays += numberOfDaysInMonth(i, year);
		}

		totalDays += day;

		return totalDays;
	}

	int numberOfDaysFromTheBeginingOfTheYear() {
		short TotalDays = 0;

		for (int i = 1; i <= _Month - 1; i++)
		{
			TotalDays += numberOfDaysInMonth(i, _Year);
		}

		TotalDays += _Day;

		return TotalDays;
	}

	static clsDate getDateFromDayOrderInYear(short dateOrderInYear, short year) {
		clsDate date;
		short remainingDays = dateOrderInYear;
		short monthDays = 0;

		date.year = year;
		date.month = 1;

		while (true) {
			monthDays = numberOfDaysInMonth(date.month, year);

			if (remainingDays > monthDays) {
				remainingDays -= monthDays;
				date.month++;
			}
			else {
				date.day = remainingDays;
				break;
			}
		}

		return date;
	}

	void addDays(short days) {
		short remainingDays = days + numberOfDaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
		short monthDays = 0;

		_Month = 1;

		while (true) {
			monthDays = numberOfDaysInMonth(_Month, _Year);

			if (remainingDays > monthDays) {
				remainingDays -= monthDays;
				_Month++;

				if (_Month > 12) {
					_Month = 1;
					_Year++;
				}

			}
			else {
				_Day = remainingDays;
				break;
			}
		}
	}

	static bool isDate1BeforeDate2(clsDate date1, clsDate date2) {
		return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
	}

	bool isDate1BeforeDate2(clsDate date2) {
		//Note: this* send the current object.
		return isDate1BeforeDate2(*this, date2);
	}

	static bool isDate1EqualsDate2(clsDate date1, clsDate date2) {
		return (date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day) ? true : false) : false) : false;
	}

	bool isDate1EqualsDate2(clsDate date2) {
		return isDate1EqualsDate2(*this, date2);
	}

	static bool isLastDayInMonth(clsDate date) {

		return (date.day == numberOfDaysInMonth(date.month, date.year));
	}

	bool isLastDayInMonth() {
		return isLastDayInMonth(*this);
	}

	static bool isLastMonthInYear(short month) {

		return (month == 12);
	}

	static clsDate addOneDay(clsDate date) {

		if (isLastDayInMonth(date)) {
			if (isLastMonthInYear(date.month)) {
				date.month = 1;
				date.day = 1;
				date.year++;
			}
			else {
				date.day = 1;
				date.month++;
			}
		}
		else {
			date.day++;
		}

		return date;
	}

	void addOneDay() {
		*this = addOneDay(*this);
	}

	static void swapDates(clsDate& Date1, clsDate& Date2) {

		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}

	static int getDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {
		//this will take care of negative diff
		int Days = 0;
		short SawpFlagValue = 1;

		if (!isDate1BeforeDate2(Date1, Date2)) {
			//Swap Dates 
			swapDates(Date1, Date2);
			SawpFlagValue = -1;
		}

		while (isDate1BeforeDate2(Date1, Date2)) {
			Days++;
			Date1 = addOneDay(Date1);
		}

		return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
	}

	int getDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return getDifferenceInDays(*this, Date2, IncludeEndDay);
	}

	static short calculateMyAgeInDays(clsDate dateOfBirth) {
		return getDifferenceInDays(dateOfBirth, clsDate::getSystemDate(), true);
	}
	//above no need to have nonstatic function for the object because it does not depend on any data from it.

	static clsDate increaseDateByOneWeek(clsDate& date) {

		for (short i = 1; i <= 7; i++) {
			date = addOneDay(date);
		}

		return date;
	}

	void increaseDateByOneWeek() {
		increaseDateByOneWeek(*this);
	}

	clsDate increaseDateByXWeeks(short weeks, clsDate& date) {

		for (short i = 1; i <= weeks; i++) {
			date = increaseDateByOneWeek(date);
		}

		return date;
	}

	void increaseDateByXWeeks(short weeks) {
		increaseDateByXWeeks(weeks, *this);
	}

	clsDate increaseDateByOneMonth(clsDate& date) {

		if (date.month == 12) {
			date.month = 1;
			date.year++;
		}
		else {
			date.month++;
		}

		//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be 31 / 2 / 2022, it should
		// be 28/2/2022
		short numberOfDaysInCurrentMonth = numberOfDaysInMonth(date.month, date.year);

		if (date.day > numberOfDaysInCurrentMonth) {
			date.day = numberOfDaysInCurrentMonth;
		}

		return date;
	}

	void increaseDateByOneMonth() {
		increaseDateByOneMonth(*this);
	}

	clsDate increaseDateByXDays(short days, clsDate& date) {

		for (short i = 1; i <= days; i++) {
			date = addOneDay(date);
		}

		return date;
	}

	void increaseDateByXDays(short days) {
		increaseDateByXDays(days, *this);
	}

	clsDate increaseDateByXMonth(short months, clsDate& date) {

		for (short i = 1; i <= months; i++) {
			date = increaseDateByOneMonth(date);
		}

		return date;
	}

	void increaseDateByXMonth(short months) {
		increaseDateByXMonth(months, *this);
	}

	static clsDate increaseDatebyOneYear(clsDate& date) {
		date.year++;
		return date;
	}

	void increaseDatebyOneYear() {
		increaseDatebyOneYear(*this);
	}

	clsDate increaseDateByXYears(short years, clsDate& date) {
		date.year += years;
		return date;
	}

	void increaseDateByXYears(short years) {
		increaseDateByXYears(years);
	}

	clsDate increaseDateByOneDecade(clsDate& date) {
		date.year += 10;
		return date;
	}

	void increaseDateByOneDecade() {
		increaseDateByOneDecade(*this);
	}

	clsDate increaseDateByXDecades(short decade, clsDate& date) {
		date.year *= 10;
		return date;
	}

	void increaseDateByXDecades(short decade) {
		increaseDateByXDecades(decade, *this);
	}

	clsDate increaseDateByOneCentury(clsDate& date) {
		date.year += 100;
		return date;
	}

	void increaseDateByOneCentury() {
		increaseDateByOneCentury(*this);
	}

	clsDate increaseDateByOneMillennium(clsDate& date) {
		date.year += 1000;
		return date;
	}

	void increaseDateByOneMillennium() {
		increaseDateByOneMillennium(*this);
	}

	static clsDate decreaseDateByOneDay(clsDate date) {
		if (date.day == 1) {
			if (date.month == 1) {
				date.month = 12;
				date.day = 31;
				date.year--;
			}
			else {
				date.month--;
				date.day = numberOfDaysInMonth(date.month, date.year);
			}
		}
		else {
			date.day--;
		}

		return date;
	}

	void decreaseDateByOneDay() {
		decreaseDateByOneDay(*this);
	}

	static clsDate decreaseDateByOneWeek(clsDate& Date) {

		for (int i = 1; i <= 7; i++) {
			Date = decreaseDateByOneDay(Date);
		}

		return Date;
	}

	void decreaseDateByOneWeek() {
		decreaseDateByOneWeek(*this);
	}

	static clsDate decreaseDateByXWeeks(short week, clsDate& date) {
		for (short i = 1; i <= week; i++) {
			date = decreaseDateByOneWeek(date);
		}
		return date;
	}

	void decreaseDateByXWeeks(short week) {
		decreaseDateByXWeeks(week, *this);
	}

	static clsDate decreaseDateByOneMonth(clsDate& date) {
		if (date.month == 1) {
			date.month = 12;
			date.year--;
		}
		else {
			date.month--;
		}

		// last check day in date should not exceed max days in the current month
		// example if date is 31/3/2022 decreasing one month should not be 31 / 2 / 2022, it should
		// be 28/2/2022

		short numberOfDaysInCurrentMonth = numberOfDaysInMonth(date.month, date.year);
		if (date.day > numberOfDaysInCurrentMonth) {
			date.day = numberOfDaysInCurrentMonth;
		}

		return date;
	}

	void decreaseDateByOneMonth() {
		decreaseDateByOneMonth(*this);
	}

	static clsDate decreaseDateByXDays(short day, clsDate& date) {
		for (short i = 1; i <= day; i++) {
			date = decreaseDateByOneDay(date);
		}
		return date;
	}

	void decreaseDateByXDays(short day) {
		decreaseDateByXDays(day, *this);
	}

	static clsDate decreaseDateByXMonth(short month, clsDate& date) {
		for (int i = 1; i <= month; i++) {
			date = decreaseDateByOneMonth(date);
		}

		return date;
	}

	void decreaseDateByXMonth(short month) {
		decreaseDateByXMonth(month, *this);
	}

	static clsDate decreaseDateByOneYear(clsDate& date) {
		date.year--;
		return date;
	}

	void decreaseDateByOneYear() {
		decreaseDateByOneYear(*this);
	}

	static clsDate decreaseDateByXYearsFaster(short year, clsDate& date) {
		date.year -= year;
		return date;
	}

	void decreaseDateByXYearsFaster(short year) {
		decreaseDateByXYearsFaster(year, *this);
	}

	static clsDate decreaseDateByOneDecade(clsDate& date) {
		date.year -= 10;
		return date;
	}

	void decreaseDateByOneDecade() {
		decreaseDateByOneDecade(*this);
	}

	static clsDate decreaseDateByXDecadesFaster(short decade, clsDate& date) {
		date.year -= decade * 10;
		return date;
	}

	void decreaseDateByXDecadesFaster(short decade) {
		decreaseDateByXDecadesFaster(decade, *this);
	}

	static clsDate decreaseDateByOneCentury(clsDate& date) {
		date.year -= 100;
		return date;
	}

	void decreaseDateByOneCentury() {
		decreaseDateByOneCentury(*this);
	}

	static clsDate decreaseDateByOneMillinum(clsDate& date) {
		date.year -= 1000;
		return date;
	}

	void decreaseDateByOneMillinum() {
		decreaseDateByOneMillinum(*this);
	}

	static short isEndOfWeek(clsDate date) {
		return dayOfWeekOrder(date.day, date.month, date.year) == 6;
	}

	short isEndOfWeek() {
		return isEndOfWeek(*this);
	}

	static bool isWeekEnd(clsDate date) {
		//Weekends are Fri and Sat
		short dayIndex = dayOfWeekOrder(date.day, date.month, date.year);
		return (dayIndex == 5 || dayIndex == 6);
	}

	bool isWeekEnd() {
		return isWeekEnd(*this);
	}

	static bool isBusinessDay(clsDate date) {
		//Weekends are Sun,Mon,Tue,Wed and Thur

	   /*
		short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
		return  (DayIndex >= 5 && DayIndex <= 4);
	   */

	   //shorter method is to invert the IsWeekEnd: this will save updating code.
		return !isWeekEnd(date);
	}

	bool isBusinessDay() {
		return isBusinessDay(*this);
	}

	static short daysUntilTheEndOfWeek(clsDate date) {
		return 6 - dayOfWeekOrder(date.day, date.month, date.year); //6 is index from 0 to 6.
	}

	short daysUntilTheEndOfWeek() {
		return daysUntilTheEndOfWeek();
	}

	static short daysUntilTheEndOfMonth(clsDate date) {
		clsDate endOfMonthDate;
		endOfMonthDate.day = numberOfDaysInMonth(date.month, date.year);
		endOfMonthDate.month = date.month;
		endOfMonthDate.year = date.year;

		return getDifferenceInDays(date, endOfMonthDate, true);
	}

	short daysUntilTheEndOfMonth() {
		return daysUntilTheEndOfMonth(*this);
	}

	static short daysUntilTheEndOfYear(clsDate date) {
		clsDate endOfYearDate;
		endOfYearDate.day = 31;
		endOfYearDate.month = 12;
		endOfYearDate.year = date.year;

		return getDifferenceInDays(date, endOfYearDate, true);
	}

	short daysUntilTheEndOfYear() {
		return daysUntilTheEndOfYear(*this);
	}

	//i added this method to calculate business days between 2 days
	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo) {

		short Days = 0;
		while (isDate1BeforeDate2(DateFrom, DateTo)) {
			if (isBusinessDay(DateFrom))
				Days++;

			DateFrom = addOneDay(DateFrom);
		}

		return Days;
	}

	static short calculateVacationDays(clsDate dateFrom, clsDate dateTo) {
		short daysCount = 0;
		while (isDate1BeforeDate2(dateFrom, dateTo)) {
			if (isBusinessDay(dateFrom)) {
				daysCount++;
			}

			dateFrom = addOneDay(dateFrom);
		}

		return daysCount;
	}

	//above method is eough , no need to have method for the object

	static clsDate calculateVacationReturnDate(clsDate dateFrom, short vacationDays) {
		short weekEndCounter = 0;
		//in case the data is weekend keep adding one day until you reach business day
		//we get rid of all weekends before the first business day
		while (isWeekEnd(dateFrom)) {
			dateFrom = addOneDay(dateFrom);
		}

		//here we increase the vacation dates to add all weekends to it.
		for (short i = 1; i <= vacationDays + weekEndCounter; i++) {
			if (isWeekEnd(dateFrom)) weekEndCounter++;

			dateFrom = addOneDay(dateFrom);
		}

		//in Case the return date is weekend keep adding one day until you reach business day
		while (isWeekEnd(dateFrom)) {
			dateFrom = addOneDay(dateFrom);
		}
		return dateFrom;
	}

	static bool isDate1AfterDate2(clsDate date1, clsDate date2) {
		return (!isDate1BeforeDate2(date1, date2)) && !isDate1EqualsDate2(date1, date2);
	}

	bool isDate1AfterDate2(clsDate date2) {
		return isDate1AfterDate2(*this, date2);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2) {
		if (isDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (isDate1EqualsDate2(Date1, Date2))
			return enDateCompare::Equal;

		/* if (IsDate1AfterDate2(Date1,Date2))
			 return enDateCompare::After;*/

			 //this is faster
		return enDateCompare::After;

	}

	enDateCompare CompareDates(clsDate Date2) {
		return CompareDates(*this, Date2);
	}
};