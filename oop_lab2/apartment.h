#include <iostream>
#include <string>
#pragma once
using namespace std;

class apartment {
public:
	apartment(); //конструктор без параметров
	apartment(string, double, int);
	apartment(const apartment& a);
	~apartment();
	string get_address();
	void set_address(string);
	double get_area();
	void set_area(double);
	int get_numberOfRooms();
	void set_numberOfRooms(int);
	void show();
private:
	string address;
	double area;
	int numberOfRooms;
};