#include <iostream>
#include <clocale>
#include <stdlib.h>
#include <ctime>
using namespace std;

void division(int N, int* first, float (*second)[10]) // значение после second надо вписывать вручую и оно равно N
{
	for (int i = 0; i < N; i++)
	{
		float a = (float(first[i]) / (N));
		for (int j = 0; j < N; j++)
		{
			second[j][i] = a;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	const int N = 10; //кол-во элементов массива
	int C = 9; //случайные числа от 0 до C-1
	int first[N];
	cout << "Массив:" << endl;
	for (int i = 0; i < N; i++)
	{
		first[i] = (rand() % C) + 1; // мы прибавили 1 чтобы не было нуля и диапазон значений стал с 1 до 9 включительно
		cout << first[i] << ' ';
	}
	cout << endl << endl;
	float second[N][N];
	division(N, first, second);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << second[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
