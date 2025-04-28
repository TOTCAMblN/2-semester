#pragma once
#include <iostream>
using namespace std;

class point {
public:
    void Init(double x, double y);
    void Read();
    void Show();
    double distance();  // Изменено на возвращение значения
private:
    double x_coordinate;
    double y_coordinate;
};