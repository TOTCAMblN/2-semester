#include "Triad.h"
#include "Date.h"
#include "iostream"
#include "clocale"
using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");
	//проверка Triad
	Triad a;
	Triad b;
	Triad c;
	cin >> a;
	cin >> b;
	if (a > b) {
		cout << "A больше B" << endl;
	}
	else { cout << "A не больше B" << endl; }
	if (a < b) {
		cout << "A меньше B" << endl;
	}
	else { cout << "A не меньше B" << endl; }
	if (a == b) {
		cout << "A равно B" << endl;
	}
	else { cout << "A не равно B" << endl; }
	c = a;
	cout << a;
	cout << b;
	cout << c;
	//проверка Date
	Date D, E, F;
	cin >> D;
	cin >> E;
	F = D;
	if (D > E) {
		cout << "D больше E" << endl;
	}
	else { cout << "D не больше E" << endl; }
	if (D < E) {
		cout << "D меньше E" << endl;
	}
	else { cout << "D не меньше E" << endl; }
	if (D == E) {
		cout << "D равно E" << endl;
	}
	else { cout << "D не равно E" << endl; }
	cout << D;
	cout << E;
	cout << F;
	return 0;
}