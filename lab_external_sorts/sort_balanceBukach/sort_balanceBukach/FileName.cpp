#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

void readF(FILE* fileRead, vector<char*>& mass)
{
	char* line = new char[256];
	while (fgets(line, 256, fileRead))
	{
		mass.push_back(line);
		line = new char[256];
	}
	return;
}

void writeF(FILE* fileWrite, vector<char*>& mass)
{
	for (int i = 0; i < mass.size(); i++)
		fputs(mass[i], fileWrite);
	return;
}

void marge(vector<char*>& F)
{
	setlocale(LC_ALL, "Russian");

	cout << "Разбиваем файл на 2 половины." << endl << endl;

	// разбиение файла на 2 половины
	int size = F.size();
	int first = (size / 2 + size % 2);
	//int second = size - first;

	vector<char*> F1, F2; // вспомогательные файлы

	int i = 0;
	for (i; i < first; i++)
		F1.push_back(F[i]);
	for (i; i < size; i++)
		F2.push_back(F[i]);
	
	cout << "Первая половина: ";
	for (int i = 0; i < F1.size(); i++)
		cout << atoi(F1[i]) << " ";

	cout << endl << "Второая половина: ";
	for (int i = 0; i < F2.size(); i++)
		cout << atoi(F2[i]) << " ";
	cout << endl << endl;

	// дробление фйлов в рекурсии
	if (F1.size() > 2)
		marge(F1);
	else if (F1.size() == 2)
	{
		if (atoi(F1[0]) > atoi(F1[1]))
		{
			char* temp = F1[0];
			F1[0] = F1[1];
			F1[1] = temp;
		}
	}

	if (F2.size() > 2)
		marge(F2);
	else if (F2.size() == 2)
	{
		if (atoi(F2[0]) > atoi(F2[1]))
		{
			char* temp = F2[0];
			F2[0] = F2[1];
			F2[1] = temp;
		}
	}

	// слияние двух файлов в один
	for (int i = 0; i < F.size(); i++)
	{
		if ((F1.size() > 0) && (F2.size() > 0))
		{
			if (atoi(F1[0]) < atoi(F2[0]))
			{
				F[i] = F1[0];
				F1.erase(F1.begin());
			}
			else
			{
				F[i] = F2[0];
				F2.erase(F2.begin());
			}
		}
		else if (F2.size() == 0)
		{
			F[i] = F1[0];
			F1.erase(F1.begin());
		}
		else if (F1.size() == 0)
		{
			F[i] = F2[0];
			F2.erase(F2.begin());
		}
	}
	cout << "Файл после сортировки: ";
	for (int i = 0; i < F.size(); i++)
		cout << atoi(F[i]) << " ";
	cout << endl << endl;

	return;
}





int main()
{
	setlocale(LC_ALL, "Russian");

	FILE* file = fopen("F.txt", "r");
	vector<char* > mass;

	readF(file, mass);
	fclose(file);

	cout << "Исходный файл: ";
	for (int i = 0; i < mass.size(); i++)
		cout << atoi(mass[i]) << " ";
	cout << endl << endl;

	marge(mass);
	
	file = fopen("F.txt", "w");
	writeF(file, mass);

	return 0;
}

