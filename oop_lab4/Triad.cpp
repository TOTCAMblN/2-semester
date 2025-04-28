#include "Triad.h"
#include <iostream>


Triad& Triad::operator=(const Triad& T)
{
	//проверка на самоприсваивание 
	if (&T == this) return*this;
	first = T.first;
	second = T.second;
	third = T.third;
	return *this;
}

bool Triad::operator<(const Triad& T)
{
	int f = first + second + third;
	int s = T.first + T.second + T.third;
	if (f < s) { return true; }
	else { return false; }
}

bool Triad::operator>(const Triad& T)
{
	int f = first + second + third;
	int s = T.first + T.second + T.third;
	if (f > s) { return true; }
	else { return false; }
}

bool Triad::operator==(const Triad& T)
{
	int f = first + second + third;
	int s = T.first + T.second + T.third;
	if (f == s) { return true; }
	else { return false; }
}

istream& operator>>(istream& in, Triad& T) {
	in >> T.first;
	in >> T.second;
	in >> T.third;
	cout << endl;
	return in;
}

ostream& operator<<(ostream& out, const Triad& T) {
	return (out << T.first << " , " << T.second << " , " << T.third << endl);
}
