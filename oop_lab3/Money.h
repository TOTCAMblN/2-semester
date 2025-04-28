#pragma once
#include <iostream>
using namespace std;

class Money {
	long rubs;
	int kops;
public:
	//������������
	Money() { rubs = 0; kops = 0; }; //����������� ��� ����������
	Money(long r, int k) { rubs = r; kops = k; };//����������� � �����������
	Money(const Money& M) { rubs = M.rubs; kops = M.kops; }; //����������� �����������
	//����������
	~Money() {}; 
	//��������� � ������������
	void set_rubs(long r) { rubs = r; }; //����������� rubs
	long get_rubs() { return rubs; }; //�������� rubs
	void set_kops(int k) { kops = k; }; //����������� kops
	int get_kops() { return kops; }; //�������� kops
	//���������� ����������
	Money& operator=(const Money&);
	bool operator<(const Money&);
	bool operator>(const Money&);
	bool operator==(const Money&);

	//���������� ������� �����-������
	friend istream& operator>>(istream& in, Money& M);
	friend ostream& operator<<(ostream& out, const Money& M);
};