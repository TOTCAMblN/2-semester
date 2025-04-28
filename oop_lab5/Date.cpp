#include "Date.h"
#include <iostream>

void Date::Show()
{
	cout << "\nFirst : " << first;
	cout << "\nSecond : " << second;
	cout << "\nThird : " << third;
	cout << "\nDay : " << day;
	cout << "\nMonth : " << month;
	cout << "\nYear : " << year;
	cout << "\n";
}


istream& operator>>(istream& in, Date& D) {
	cout << "������� ����:";
	in >> D.first;
	D.day= D.first;
	cout << "������� �����:";
	in >> D.second;
	D.month = D.second;
	cout << "������� ���:";
	in >> D.third;
	D.year = D.third;
	cout << endl;
	return in;
}

ostream& operator<<(ostream& out, const Date& D) {
	return (out << D.day << '.' << D.month << '.' << D.year << endl);
}

bool Date::operator<(const Date& D) {
	if (year < D.year) { return true; }
	else {
		if (month < D.month) { return true; }
		else {
			if (day < D.day) { return true; }
			else { return false; }
		}
	}
}

bool Date::operator>(const Date& D) {
	if (year > D.year) { return true; }
	else {
		if (month > D.month) { return true; }
		else {
			if (day > D.day) { return true; }
			else { return false; }
		}
	}
}

bool Date::operator==(const Date& D) {
	if (year == D.year) { return true; }
	else {
		if (month == D.month) { return true; }
		else {
			if (day == D.day) { return true; }
			else { return false; }
		}
	}
}