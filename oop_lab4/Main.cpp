#include "Triad.h"
#include "Date.h"
#include "iostream"
#include "clocale"
using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");
	//�������� Triad
	Triad a;
	Triad b;
	Triad c;
	cin >> a;
	cin >> b;
	if (a > b) {
		cout << "A ������ B" << endl;
	}
	else { cout << "A �� ������ B" << endl; }
	if (a < b) {
		cout << "A ������ B" << endl;
	}
	else { cout << "A �� ������ B" << endl; }
	if (a == b) {
		cout << "A ����� B" << endl;
	}
	else { cout << "A �� ����� B" << endl; }
	c = a;
	cout << a;
	cout << b;
	cout << c;
	//�������� Date
	Date D, E, F;
	cin >> D;
	cin >> E;
	F = D;
	if (D > E) {
		cout << "D ������ E" << endl;
	}
	else { cout << "D �� ������ E" << endl; }
	if (D < E) {
		cout << "D ������ E" << endl;
	}
	else { cout << "D �� ������ E" << endl; }
	if (D == E) {
		cout << "D ����� E" << endl;
	}
	else { cout << "D �� ����� E" << endl; }
	cout << D;
	cout << E;
	cout << F;
	return 0;
}