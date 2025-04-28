//23.	Структура "Стадион":
//-название;
//-год постройки;
//-количество площадок;
//-виды спорта.
// 
//  Удалить все элементы, у которых год постройки меньше заданного, добавить 2 элемента перед элементом с указанным номером.
//
#include <iostream>
#include <clocale>
#include <string>
#include <fstream>
using namespace std;

struct stadium{
	string name;
	int year;
	int count;
	string sports;
	void addData(string addname, int addyear, int addcount, string addsports) {
		name = addname;
		year = addyear;
		count = addcount;
		sports = addsports;
	}
	void print() {
		cout << name << endl;
		cout << year << endl;
		cout << count << endl;
		cout << sports << endl;
		cout << "--------------------------" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Ru");
	ifstream in;
	ofstream out;
	string line;

	in.open("text.txt");

	int N;

	getline(in,line);

	N = stoi(line); //преобразование строки в целое число

	int M = 0;

	stadium* array = new stadium[M];

	string name;
	int year;
	int count;
	string sports;

	cout << "Введите год:" << endl;
	int rightyear;
	cin >> rightyear;

	for (int i = 0; i < N; i++) {
		getline(in,line, ' ');
		name = line;
		getline(in, line, ' ');
		year = stoi(line);
		getline(in, line, ' ');
		count = stoi(line);
		getline(in, line);
		sports = line;
		if (year >= rightyear) {
			stadium* temp = new stadium[M+1];
			for (int j = 0; j < M; j++) {
				temp[j] = array[j];
			}
			delete[] array;
			array = temp;
			M++;
			array[M-1].addData(name, year, count, sports);
		}
	}
	out.open("text.txt");

	int number;

	for (int i = 0; i < M; i++) {
		cout << i + 1 << ". ";
		array[i].print();
	}

	cout << "Укажите номер:" << endl;
	cin >> number;

	if (number - 1 >= M || number <1) {
		cout << "Введен неподходящий номер!";
		return 1;
	}

	M = M + 2;

	int index = number - 1;

	string name1, name2, sports1, sports2;
	int year1, year2, count1, count2;

	cout << "Введите название первого стадиона:" << endl;
	cin >> name1;
	cout << "Введите год первого стадиона:" << endl;
	cin >> year1;
	cout << "Введите количество мест на первом стадионе:" << endl;
	cin >> count1;
	cout << "Введите вид спорта первого стадиона:" << endl;
	cin >> sports1;

	cout << "Введите название второго стадиона:" << endl;
	cin >> name2;
	cout << "Введите год второго стадиона:" << endl;
	cin >> year2;
	cout << "Введите количество мест на втором стадионе:" << endl;
	cin >> count2;
	cout << "Введите вид спорта второго стадиона:" << endl;
	cin >> sports2;

	stadium* temp = new stadium[M + 2];
	for (int j = 0; j < index; j++) {
		temp[j] = array[j];
	}
	temp[index].addData(name1,year1,count1,sports1);
	temp[index+1].addData(name2, year2, count2, sports2);
	for (int j = index; j < M-2; j++) {
		temp[j+2] = array[j];
	}
	delete[] array;
	array = temp;

	for (int i = 0; i < M; i++) {
		cout << i + 1 << ". ";
		array[i].print();
	}

	out << M << endl;
	
	for (int i = 0; i < M; i++) {
		out << array[i].name << ' ';
		out << array[i].year << ' ';
		out << array[i].count << ' ';
		out << array[i].sports << endl;
	}

	out.close();
	in.close();
	delete[] array;
	return 0;
}