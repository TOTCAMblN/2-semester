#include <iostream>
#include <clocale>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251); // ��������� ����� Windows-1251
    SetConsoleOutputCP(1251); // ��������� ������ Windows-1251
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "������� ���������� ����� � �������:" << endl;
    cin >> n;

    string* array = new string[n]; // �������� ������ ��� ������� �����

    // ���� �����
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    // �������� ����������
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n;) // j++ ������ ���� �� ������� �������
        {
            if (array[i] == array[j])
            {
                // ������� ����� ������ �� 1 ������� ������
                string* temp = new string[n - 1];

                // �������� ��������, �������� ��������
                for (int k = 0, m = 0; k < n; k++)
                {
                    if (k != j) // ���������� ��������
                    {
                        temp[m] = array[k];
                        m++;
                    }
                }

                delete[] array; // ����������� ������ ������
                array = temp; // ��������� �� ����� ������
                n--; // ��������� ������ �������

                // �� ����������� j, ��� ��� �������� ������� ������� ����������� �����
            }
            else
            {
                j++; // ����������� ������ ���� ������� �� �����
            }
        }
    }

    // ����� ������� ��� ����������
    cout << "������ ��� ����������:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ' ';
    }

    delete[] array; // ����������� ������ ����� �������

    cout << endl << "������� ���������� ����� � �������:" << endl;
    cin >> n;

    array = new string[n]; // �������� ������ ��� ������� �����

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "������� �������� k:" << endl;
    int k;
    cin >> k;
    if (k > n)
    {
        cout << "������� ������� ��������";
        return 0;
    }
    n = n-k;
    string* temp = new string[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
    cout << "������ ��� k ��������� �����:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ' ';
    }

    delete[] array;

    return 0;
}