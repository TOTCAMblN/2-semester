#include <iostream>
#include <clocale>
using namespace std;

void show_array(int n,int* array) // ���������, ��������� ������
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "������� ���������� ��������� �������:" << endl;
	int n; // ���-�� ��������� �������
	cin >> n;
	int k;
	cout << "������� �������� ��������� �������" << endl;
	int* array = new int[n];
	for (int i = 0; i < n; i++) // ���� �������
	{
		cin >> array[i];
	}
	cout << "������� ����� � �������� ����� ���������� ������" << endl;
	cin >> k;
	k = (k % n)-1;
	int temp;
	for (int i = 0; i < k; i++)
	{
		temp = array[0];
		for (int j = 0; j < (n - 1); j++)
		{
			array[j] = array[j + 1];
		}
		array[n - 1] = temp;
	}
	show_array(n, array);
	int max = -2147483648;
	for (int i = 0; i < n; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	for (int i = 0; i < n;)
	{
		if (array[i] == max)
		{
			int* temp = new int[n - 1];
			for (int k = 0, m = 0; k < n; k++)
			{
				if (array[k] != max) // ���������� ��������
				{
					temp[m] = array[k];
					m++;
				}
			}
			delete[] array; // ����������� ������ ������
			array = temp; // ��������� �� ����� ������
			n--; // ��������� ������ �������
		}
		else
		{
			i++;
		}
	}
	show_array(n, array);
	for (int i = 0; i < k*2; i++)
	{
		temp = array[n-1];
		for (int j = (n-1); j > 0; j--)
		{
			array[j] = array[j - 1];
		}
		array[0] = temp;
	}
	show_array(n, array);
	return 0;
}