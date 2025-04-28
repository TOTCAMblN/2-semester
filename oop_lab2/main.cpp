#include "apartment.h" 
#include <iostream> 
#include <string> 
using namespace std;
//функция для возврата объекта как результата 
apartment make_apartment()
{
	string s;
	int i;
	double d;

	cout << "Введите адрес: ";
	cin >> s;
	cout << "Введие количество комнат: ";
	cin >> i;
	cout << "Введите площадь: "; 
	cin >> d;

	apartment a(s, i, d);
	return a;
}
//функция для передачи объекта как параметра 
void print_apartment(apartment a)
{
	a.show();
}
int main()
{
	setlocale(LC_ALL, "Ru");
	system("chcp 1251");
	//конструктор без параметров 
	apartment a1;
	a1.show();
	//коструктор с параметрами 
	apartment a2("Улица Пушкина, дом Колотушкина", 20,15000);
	a2.show();
	//конструктор копирования
	apartment a3=a2;
	a3.set_address("Улица Берии"); 
	a3.set_numberOfRooms(2);
	a3.set_area(5000.0);
	//конструктор копирования
	print_apartment(a3);
	//конструктор копирования 
	a1=make_apartment();
	a1.show();
	return 0;
}
