#include <iostream>
#include <clocale>
#include <string>
using namespace std;

int main()
{
	string array[2][100] = { {"_THIS_", "_TABLE_","_IS_","_A_","_"," "}, {"_���_", "_����_","_","_"," ","_"}};

	setlocale(LC_ALL, "ru");
	system("chcp 65001");
	string phrase;
	string translate;
	cout << "������� ����������� ����� ������:" << endl;
	cin >> phrase; // ����: THIS_IS_A_TABLE 18446744073709551615
	phrase.insert(0, "_");
	phrase.insert(phrase.size(), "_");

	int word;

	for (int i = 0; i < 6; i++) // ������ �� ��������� �������
	{
		while (phrase.find(array[0][i], 0)!= 18446744073709551615) { //���� ������� ����� �� ������� � ������
			word = phrase.find(array[0][i], 0);
			phrase.erase(word, size(array[0][i]));
			phrase.insert(word, array[1][i]);
		}
	}
	phrase.erase(0, 1);
	phrase.erase(phrase.size()-1,1);
	cout << phrase;
	return 0;
}