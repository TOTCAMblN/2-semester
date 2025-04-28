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
	//Конструкторы
	Triad() { first = 0; second = 0; third = 0; }; //Конструктор без параметров
	Triad(int f, int s, int t) { first = f; second = s; third = t; };//Конструктор с параметрами
	Triad(const Triad& T) { first = T.first; second = T.second; third = T.third; }; //Конструктор копирования
	//Деструктор
	~Triad() {};
	//
	void Show();
	//Селекторы и модификаторы
	void set_first(int f) { first = f; }; //модификатор first
	int get_first() { return first; }; //селектор first
	void set_second(int s) { second = s; }; //модификатор second
	int get_second() { return second; }; //селектор second
	void set_third(int t) { third = t; }; //модификатор second
	int get_third() { return third; }; //селектор second
	//Перегрузки операторов
	Triad& operator=(const Triad&);
	bool operator<(const Triad&);
	bool operator>(const Triad&);
	bool operator==(const Triad&);

	//Глобальные функции ввода-вывода
	friend istream& operator>>(istream& in, Triad& T);
	friend ostream& operator<<(ostream& out, const Triad& T);
};
