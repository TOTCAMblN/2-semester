#include "class.h"
#include <cmath>

void point::Init(double x, double y) {
    x_coordinate = x;
    y_coordinate = y;
}

void point::Read() {
    cout << "\nfirst?";
    cin >> x_coordinate;
    cout << "\nsecond?";
    cin >> y_coordinate;
}

void point::Show() {
    cout <<"first: "<< x_coordinate;
    cout <<"second: " << y_coordinate;
    cout << endl;
}

double point::distance() {
    return sqrt(pow(x_coordinate, 2) + pow(y_coordinate, 2));
}