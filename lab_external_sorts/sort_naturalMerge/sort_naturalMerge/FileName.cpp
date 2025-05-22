#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

void fread(vector<char*>& mass, FILE*& FileRead)
{
	char* line = new char[256];
	while (fgets(line, 256, FileRead))
	{
		mass.push_back(line);
		line = new char[256];
	}
	return;
}

void fwrite(vector<char*>& mass, FILE* FileWrite)
{
	for (int i = 0; i < mass.size(); i++)
		fputs(mass[i], FileWrite);
}

void vivo(vector<char*>& F, vector<char*>& F1, vector<char*>& F2)
{
	cout << "F: ";
	for (int i = 0; i < F.size(); i++)
		cout << atoi(F[i]) << " ";
	cout << endl << "F1: ";
	for (int i = 0; i < F1.size(); i++)
		cout << atoi(F1[i]) << " ";
	cout << endl << "F2: ";
	for (int i = 0; i < F2.size(); i++)
		cout << atoi(F2[i]) << " ";
	cout << endl << endl;
}
void marge(vector<char*>& F, vector<char*>& F1, vector<char*>& F2) // алгоритм сортировки
{
	/*cout << "Изначальный файл:" << endl << endl << "F: ";
	for (int i = 0; i < F.size(); i++)
		cout << atoi(F[i]) << " ";
	cout << endl << endl;*/
	//распределение между 2 файлами
	int i = 0;
	F1.push_back(F[i]);
	i++;
	while ((i < F.size()) && (atoi(F1.back()) <= atoi(F[i])))
	{
		F1.push_back(F[i]);
		i++;
	}
	
	if (F1.size() < F.size())
	{
		F2.push_back(F[i]);
		i++;
	}
	while ((i < F.size()) && (atoi(F2.back()) <= atoi(F[i])))
	{
		F2.push_back(F[i]);
		i++;
	}
	/*cout << "Выделение серий" << endl << endl << "F1: ";
	for (int i = 0; i < F1.size(); i++)
		cout << atoi(F1[i]) << " ";
	cout << endl << "F2: ";
	for (int i = 0; i < F2.size(); i++)
		cout << atoi(F2[i]) << " ";

	cout << endl << endl;*/
	// алгоритм сортировки
	int step = F1.size() + F2.size();
	bool flag = true;
	if (F1.size() == F.size())
		flag = false;


	for (int i = 0; i < step; i++)
	{
		if ((F1.size() > 0) && (F2.size() > 0))
		{
			if (atoi(F1[0]) <= atoi(F2[0]))
			{
				F[i] = F1[0];
				F1.erase(F1.begin());
				//vivo(F, F1, F2);

			}

			else
			{
				F[i] = F2[0];
				F2.erase(F2.begin());
				//vivo(F, F1, F2);
			}
		}
		else if ((F1.size() == 0) && (F2.size() != 0))
		{
			F[i] = F2[0];
			F2.erase(F2.begin());
			//vivo(F, F1, F2);
		}
		else if ((F1.size() != 0) && (F2.size() == 0))
		{
			F[i] = F1[0];
			F1.erase(F1.begin());
			//vivo(F, F1, F2);
		}
	}


	if (flag)
	{
		marge(F, F1, F2);
	}
	
}

int main()
{
	setlocale(LC_ALL, "Russian");
	FILE* f = fopen("F.txt", "r");
	vector<char*> F; // имитация исходного файла 
	fread(F, f);
	fclose(f);

	vector<char*> F1, F2; // имитация вспомогательных файлов
	
	marge(F, F1, F2);

	f = fopen("F.txt", "w");
	fwrite(F, f);
	fclose(f);

	for (int i = 0; i < F.size(); i++)
		delete[] F[i];
	return 0;
}