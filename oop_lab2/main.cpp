#include "apartment.h" 
#include <iostream> 
#include <string> 
using namespace std;
//������� ��� �������� ������� ��� ���������� 
apartment make_apartment()
{
	string s;
	int i;
	double d;

	cout << "������� �����: ";
	cin >> s;
	cout << "������ ���������� ������: ";
	cin >> i;
	cout << "������� �������: "; 
	cin >> d;

	apartment a(s, i, d);
	return a;
}
//������� ��� �������� ������� ��� ��������� 
void print_apartment(apartment a)
{
	a.show();
}
int main()
{
	setlocale(LC_ALL, "Ru");
	system("chcp 1251");
	//����������� ��� ���������� 
	apartment a1;
	a1.show();
	//���������� � ����������� 
	apartment a2("����� �������, ��� �����������", 20,15000);
	a2.show();
	//����������� �����������
	apartment a3=a2;
	a3.set_address("����� �����"); 
	a3.set_numberOfRooms(2);
	a3.set_area(5000.0);
	//����������� �����������
	print_apartment(a3);
	//����������� ����������� 
	a1=make_apartment();
	a1.show();
	return 0;
}
