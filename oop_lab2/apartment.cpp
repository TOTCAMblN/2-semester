#include <iostream>
#include <string>
#include "apartment.h"
using namespace std;
//конструктор без параметров 
apartment::apartment()
{
	address = "";
	numberOfRooms = 0;
	area = 0;
	cout << " онструктор без параметров" << this << endl;
}
//конструктор с параметрами 
apartment::apartment(string N, double S, int K)
{
	address = N;
	numberOfRooms = K;
	area = S;
	cout << " онструктор с параметрами" << this << endl;
}
//конструктор копировани€ 
apartment::apartment(const apartment &a)
{
	address = a.address;
	numberOfRooms = a.numberOfRooms;
	area = a.area;

	cout << " онструктор копировани€" << this << endl;
}
//деструктор 
apartment::~apartment()
{
	cout << "ƒеструктор" << this << endl;
}
//селекторы
string apartment::get_address()
{
	return address;
}
int apartment::get_numberOfRooms()
{
	return numberOfRooms;
}
double apartment::get_area()
{
	return area;
}
//модификаторы
void apartment::set_address(string N)
{
	address = N;
}
void apartment::set_numberOfRooms(int K)
{
	numberOfRooms = K;
}
void apartment::set_area(double S)
{
	area = S;
}
//метод дл€ просмотра атрибутов 
void apartment::show()
{
	cout << "address :" << address << endl;
	cout << "numberOfRooms :" << numberOfRooms << endl;
	cout << "area :" << area << endl;
}
