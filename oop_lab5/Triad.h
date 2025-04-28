#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Triad:public Object {
protected:
	int first;
	int second;
	int third;
public:
	//������������
	Triad() { first = 0; second = 0; third = 0; }; //����������� ��� ����������
	Triad(int f, int s, int t) { first = f; second = s; third = t; };//����������� � �����������
	Triad(const Triad& T) { first = T.first; second = T.second; third = T.third; }; //����������� �����������
	//����������
	~Triad() {};
	//
	void Show();
	//��������� � ������������
	void set_first(int f) { first = f; }; //����������� first
	int get_first() { return first; }; //�������� first
	void set_second(int s) { second = s; }; //����������� second
	int get_second() { return second; }; //�������� second
	void set_third(int t) { third = t; }; //����������� second
	int get_third() { return third; }; //�������� second
	//���������� ����������
	Triad& operator=(const Triad&);
	bool operator<(const Triad&);
	bool operator>(const Triad&);
	bool operator==(const Triad&);

	//���������� ������� �����-������
	friend istream& operator>>(istream& in, Triad& T);
	friend ostream& operator<<(ostream& out, const Triad& T);
};
