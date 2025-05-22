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

	cout << "��������� ���� �� 2 ��������." << endl << endl;

	// ��������� ����� �� 2 ��������
	int size = F.size();
	int first = (size / 2 + size % 2);
	//int second = size - first;

	vector<char*> F1, F2; // ��������������� �����

	int i = 0;
	for (i; i < first; i++)
		F1.push_back(F[i]);
	for (i; i < size; i++)
		F2.push_back(F[i]);
	
	cout << "������ ��������: ";
	for (int i = 0; i < F1.size(); i++)
		cout << atoi(F1[i]) << " ";

	cout << endl << "������� ��������: ";
	for (int i = 0; i < F2.size(); i++)
		cout << atoi(F2[i]) << " ";
	cout << endl << endl;

	// ��������� ����� � ��������
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

	// ������� ���� ������ � ����
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
	cout << "���� ����� ����������: ";
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

	cout << "�������� ����: ";
	for (int i = 0; i < mass.size(); i++)
		cout << atoi(mass[i]) << " ";
	cout << endl << endl;

	marge(mass);
	
	file = fopen("F.txt", "w");
	writeF(file, mass);

	return 0;
}

