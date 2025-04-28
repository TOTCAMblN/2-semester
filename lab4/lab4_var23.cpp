#include <iostream>
#include <clocale>
using namespace std;

void show_array(int n,int* array) // процедура, выводящая массив
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
	cout << "Введите количество элементов массива:" << endl;
	int n; // кол-во элементов массива
	cin >> n;
	int k;
	cout << "Введите значения элементов массива" << endl;
	int* array = new int[n];
	for (int i = 0; i < n; i++) // ввод массива
	{
		cin >> array[i];
	}
	cout << "Введите номер с которого будет начинаться кольцо" << endl;
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
				if (array[k] != max) // Пропускаем дубликат
				{
					temp[m] = array[k];
					m++;
				}
			}
			delete[] array; // Освобождаем старую память
			array = temp; // Указываем на новый массив
			n--; // Уменьшаем размер массива
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