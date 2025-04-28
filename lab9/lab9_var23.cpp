#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
using namespace std;

static const size_t npos = -1;

int main() {
	setlocale(LC_ALL, "Ru");

	// 1) 	����������� �� ����� F1 � ���� F2 ��� ������, � ������� ���������� ������ ���� �����.

	ifstream in1;
	ofstream out1;

	in1.open("F1.txt");
	out1.open("F2.txt");

	string line1;

	if (in1.is_open()) {
		while (getline(in1, line1)) {
			if (line1.find(' ') == npos) {
				out1 << line1 << endl;
			}
		}
	}

	in1.close();
	out1.close();

	// 2) 	���������� ����� �����, � ������� ������ ����� ��������� ����.

	ifstream in2;

	in2.open("F2.txt");

	int lettercounter;
	int wordcounter=1;
	int max = 0;
	int number;

	char RUvowels[20] = { '�','a','�', '�', '�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�' };

	string line2;
	int len;
	bool result;

	if (in2.is_open()) {
		while (getline(in2, line2)) {
			len = line2.size();
			lettercounter = 0;
			for (int i = 0; i < len; i++) {
				for (int j = 0; j < 20; j++) {
					if (line2[i] != RUvowels[j]) {
						lettercounter++;
					}
				}
			}
			if (lettercounter > max) {
				max = lettercounter;
				number = wordcounter;
			}
			wordcounter++;
		}
	}

	cout <<"����� �����, � ������� ������ ����� ��������� ����: "<< number << endl;

	return 0;
}