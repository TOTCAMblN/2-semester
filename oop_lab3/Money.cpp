#include "Money.h"
#include <iostream>
using namespace std;

Money&Money::operator=(const Money& M)
{
	//проверка на самоприсваивание 
	if (&M==this) return*this;
	rubs = M.rubs;
	kops = M.kops;
	return *this;
}

bool Money::operator<(const Money& M)
{
	if (rubs < M.rubs)return true;
	if (rubs == M.rubs) {
		if (kops < M.kops) {
			return true;
		}
		else return false;
	}
	return false;
	
}

bool Money::operator>(const Money& M)
{
	if (rubs > M.rubs)return true;
	if (rubs == M.rubs) {
		if (kops > M.kops) {
			return true;
		}
		else return false;
	}
	return false;
}

bool Money::operator==(const Money& M)
{
	if (rubs == M.rubs) {
		if (kops == M.kops) {
			return true;
		}
		else return false;
	}
	else return false;
}

istream& operator>>(istream& in, Money& M) {
	cout << "Введите рубли:"; 
	in >> M.rubs; 
	cout << "Введите копейки:";
	in >> M.kops;
	cout << endl;
	return in;
}

ostream& operator<<(ostream& out, const Money& M) {
	return (out << M.rubs << "," << M.kops);
}
