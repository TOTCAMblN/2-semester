#include "Object.h" 
#include "Triad.h" 
#include "Date.h" 
#include "Vector.h" 
#include <string> 
#include <iostream> 
using namespace std; 
void main()
{
	setlocale(LC_ALL, "Ru");
	Vector v(5);//������ �� 5 ��������� 
	Triad a;//������ ������ Triad
	cin >> a;
	Date b;// ������ ������ Date
	cin>>b;
	Object* p = &a;//������ ��������� �� ������ ������ Car 
	v.Add(p);//��������� ������ � ������
	p = &b;//������ ��������� �� ������ ������ Lorry 
	v.Add(p); //��������� ������ � ������ 
	cout<<v;//����� �������
}
