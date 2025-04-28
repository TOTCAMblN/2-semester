#include <iostream>
#include <clocale>
#include <cmath>
#include <cstdarg> // ���������� ��� ������ � ��������� � ���������� ������ ����������
using namespace std;

struct cord {
    int x;
    int y;
    void add(int x1, int y1) {
        x = x1;
        y = y1;
    }
};

double sidelength(cord A, cord B) { //�������, ������� ������� ����� ������� �� ����������� ��� �����
	return (sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2)));
}


double trianglearea(cord A, cord B, cord C){ //������� ����� ������� ������������
    double a = sidelength(B, C);
    double b = sidelength(A, C);
    double c = sidelength(A, B);

    double p = 0.5 * (a + b + c);

    return (sqrt(p * (p - a) * (p - b) * (p - c)));
}

// ������� ��� �����������, ����������� �� ����� M ������������ ABC
bool belong(cord M, cord A, cord B, cord C) {
    // ���������� ������� � ������ �����������
    const double epsilon = 1e-6;
    if (abs(trianglearea(A, B, C) - (trianglearea(M, B, C) + trianglearea(A, M, C) + trianglearea(A, B, M))) < epsilon) {
        return true;
    }
    else {
        return false;
    }
}   

bool magic(int N, cord M, ...) {
    va_list args;
    va_start(args, M);

    // ������� ������ ��� �������� ������ ��������������
    cord* points = new cord[N];
    for (int i = 0; i < N; i++) {
        points[i] = va_arg(args, cord);
    }
    va_end(args);

    // ��������� ������� ��������������
    double totalArea = 0.0;
    for (int i = 1; i < N - 1; i++) {
        totalArea += trianglearea(points[0], points[i], points[i + 1]);
    }

    //totalArea += (trianglearea(points[N - 1], points[N - 2], points[0]));

    // ��������� ����� �������� �������������, ������������ ������ M � ������ ����� �������� ������
    double sumArea = 0.0;
    for (int i = 0; i < N; i++) {
        int next = (i + 1) % N; // ��������� ������� (� ������ ��������� �� ������)
        sumArea += trianglearea(M, points[i], points[next]);
    }

    delete[] points; // ����������� ������

    // ���������� ������� � ������ �����������
    const double epsilon = 1e-6;
    return abs(totalArea - sumArea) < epsilon;
}


int main()
{
    setlocale(LC_ALL, "RU");
    cord A, B, C, M;
    int x, y; 

    cout << "�������� ������ �������" << endl;

    cout << "������� ����� �������� X ������ �����:" << endl;
    cin >> x;
    cout << "������� ����� �������� Y ������ �����:" << endl;
    cin >> y;

    A.add(x, y);


    cout << "������� ����� �������� X ������ �����:" << endl;
    cin >> x;
    cout << "������� ����� �������� Y ������ �����:" << endl;
    cin >> y;

    B.add(x, y);

    cout << "������ ����� ����� �������: " << sidelength(A, B) << endl;

    cout << "�������� ������ �������" << endl;

    cout << "������� ����� �������� X ����� A:" << endl;
    cin >> x;
    cout << "������� ����� �������� Y ����� A:" << endl;
    cin >> y;

    A.add(x, y);

    cout << "������� ����� �������� X ����� B:" << endl;
    cin >> x;
    cout << "������� ����� �������� Y ����� B:" << endl;
    cin >> y;

    B.add(x, y);

    cout << "������� ����� �������� X ����� C:" << endl;
    cin >> x;
    cout << "������� ����� �������� Y ����� C:" << endl;
    cin >> y;

    C.add(x, y);

    cout << "������� ����� �������� X ����� M:" << endl;
    cin >> x;
    cout << "������� ����� �������� Y ����� M:" << endl;
    cin >> y;

    M.add(x, y);

    if (belong(M, A, C, B)==true) {
        cout << "����� M ����������� ������������ ABC" << endl;
    }
    else {
        cout << "����� M �� ����������� ������������ ABC" << endl;
    }

    int N;
    cout << "������� ���������� ������ �������������� �� 3 �� 10 ������: ";
    cin >> N;

    if (N < 3) {
        cout << "������������� ������ ����� ���� �� 3 �������!" << endl;
        return 1;
    }

    if (N > 10) {
        cout << "������� ����� ������!" << endl;
        return 2;
    }

    // ������� ������ ��� �������� ������ ��������������
    cord* points = new cord[N];
    for (int i = 0; i < N; i++) {
        cout << "������� ����� �������� X ����� " << i + 1 << " : ";
        cin >> points[i].x;
        cout << "������� ����� �������� Y ����� " << i + 1 << " : ";
        cin >> points[i].y;
    }

    cout << "������� ����� �������� X ����� M: ";
    cin >> M.x;
    cout << "������� ����� �������� Y ����� M: ";
    cin >> M.y;

    // ����� ������� magic ��� �������� �������������� ����� M ��������������
    if (magic(N, M, points[0], points[1], points[2], points[3], points[4], points[5], points[6], points[7], points[8], points[9])) {
        cout << "����� M ����������� ��������������." << endl;
    }
    else {
        cout << "����� M �� ����������� ��������������." << endl;
    }

    delete[] points; // ����������� ������

	return 0;
}