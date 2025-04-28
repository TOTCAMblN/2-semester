#pragma once
#include <iostream>
using namespace std;

class Money {
	long rubs;
	int kops;
public:
	//Конструкторы
	Money() { rubs = 0; kops = 0; }; //Конструктор без параметров
	Money(long r, int k) { rubs = r; kops = k; };//Конструктор с параметрами
	Money(const Money& M) { rubs = M.rubs; kops = M.kops; }; //Конструктор копирования
	//Деструктор
	~Money() {}; 
	//Селекторы и модификаторы
	void set_rubs(long r) { rubs = r; }; //модификатор rubs
	long get_rubs() { return rubs; }; //селектор rubs
	void set_kops(int k) { kops = k; }; //модификатор kops
	int get_kops() { return kops; }; //селектор kops
	//Перегрузки операторов
	Money& operator=(const Money&);
	bool operator<(const Money&);
	bool operator>(const Money&);
	bool operator==(const Money&);

	//Глобальные функции ввода-вывода
	friend istream& operator>>(istream& in, Money& M);
	friend ostream& operator<<(ostream& out, const Money& M);
};