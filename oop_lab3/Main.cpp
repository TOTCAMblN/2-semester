#include "Money.h"
#include <iostream>
#include <clocale>
using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");
	Money a;//����������� ��� ���������� 
	Money b; //����������� ��� ���������� 
	Money c; //����������� ��� ���������� 
	cin>>a;//���� ����������
	cin>>b;//���� ����������

	if (a > b) {
		cout << "A ������ B" << endl;
	}
	else {
		cout << "A �� ������ B" << endl;
	}
	if (a < b) {
		cout << "A ������ B" << endl;
	}
	else {
		cout << "A �� ������ B" << endl;
	}
	if (a == b) {
		cout << "A ����� B" << endl;
	}
	else {
		cout << "A �� ����� B" << endl;
	}
	c = a;
	cout<<"A="<<a<<endl; //����� ����������
	cout<<"B="<<b<<endl; //����� ����������
	cout<<"C="<<c<<endl; //����� ����������
	return 0;
}