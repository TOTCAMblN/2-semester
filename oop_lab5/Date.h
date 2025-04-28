#pragma once
#include "Triad.h"
class Date : public Triad{
public:
	Date() { day = first; month = second; year = third; }; //Конструктор без параметров
	Date(int f, int s, int t) { day = f; month = s; year = t; };
	Date(const Date& D) { first = D.first; second = D.second; third = D.third; day = D.day; month = D.month; year = D.year;};
	~Date() {}; //Деструктор

	bool operator<(const Date&);
	bool operator>(const Date&);
	bool operator==(const Date&);

	void Show();

	friend istream& operator>>(istream& in, Date& D);
	friend ostream& operator<<(ostream& out, const Date& D);
private:
	int day;
	int month;
	int year;
};
