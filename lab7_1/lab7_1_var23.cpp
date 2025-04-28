#include <iostream>
#include <clocale>
using namespace std;

void shift(int* array, float result, int n) {
	int count = array[0];
	for (int i = 0; i < count; i++) {
		int temp = array[0];
		for (int j = 0; j < n-1; j++)
		{
			array[j] = array[j+1];
		}
		array[n-1] = temp;
	}
}

void shift(int* array, int result, int n) {
	int count = array[n - 1];
	for (int i = 0; i < count; i++) {
		int temp = array[n-1];
		for (int j = n-1; j > 0 ; j--)
		{
			array[j] = array[j-1];
		}
		array[0] = temp;
	}
}

void proverka(int* array, int n)
{
	if (array[0] % 2 != 0)
	{
		cout << "нечет" << endl;
		int result = 1;
		shift(array, result, n);
	}
	else {
		cout << "чет" << endl;
		float result = 1;
		shift(array, result, n);
	}
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << ' ';
	}
}

const int n = 10;

int main()
{
	setlocale(LC_ALL, "ru");
	int array[n] = { 1,2,3,4,5,6,7,8,9,2 };
	proverka(array, n);
	return 0;
}