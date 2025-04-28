#include <clocale>
#include <iostream>
#include "class.h"
using namespace std;

int main() {
    point A, B;
    A.Read();
    A.Show();
    B.Init(4, 5);
    B.Show();
    cout << A.distance() << endl;
    cout << B.distance();
    return 0;
}