#include <iostream>
#include <string>
#include "apartment.h"
using namespace std;
//����������� ��� ���������� 
apartment::apartment()
{
	address = "";
	numberOfRooms = 0;
	area = 0;
	cout << "����������� ��� ����������" << this << endl;
}
//����������� � ����������� 
apartment::apartment(string N, double S, int K)
{
	address = N;
	numberOfRooms = K;
	area = S;
	cout << "����������� � �����������" << this << endl;
}
//����������� ����������� 
apartment::apartment(const apartment &a)
{
	address = a.address;
	numberOfRooms = a.numberOfRooms;
	area = a.area;

	cout << "����������� �����������" << this << endl;
}
//���������� 
apartment::~apartment()
{
	cout << "����������" << this << endl;
}
//���������
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
//������������
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
//����� ��� ��������� ��������� 
void apartment::show()
{
	cout << "address :" << address << endl;
	cout << "numberOfRooms :" << numberOfRooms << endl;
	cout << "area :" << area << endl;
}
