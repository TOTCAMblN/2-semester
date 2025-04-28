#include "Money.h"
#include <iostream>
#include <clocale>
using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");
	Money a;//конструктор без параметров 
	Money b; //конструктор без параметров 
	Money c; //конструктор без параметров 
	cin>>a;//ввод переменной
	cin>>b;//ввод переменной

	if (a > b) {
		cout << "A больше B" << endl;
	}
	else {
		cout << "A не больше B" << endl;
	}
	if (a < b) {
		cout << "A меньше B" << endl;
	}
	else {
		cout << "A не меньше B" << endl;
	}
	if (a == b) {
		cout << "A равен B" << endl;
	}
	else {
		cout << "A не равен B" << endl;
	}
	c = a;
	cout<<"A="<<a<<endl; //вывод переменной
	cout<<"B="<<b<<endl; //вывод переменной
	cout<<"C="<<c<<endl; //вывод переменной
	return 0;
}