#include <iostream>
#include <clocale>
#include <windows.h>
using namespace std;

const int MAX_SIZE = 100; // ������������ ������ �����

struct Stack {
    char data[MAX_SIZE];
    int top = -1; // ������ ������� �����

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(char value) {
        if (isFull()) {
            cout << "���� ����������!" << endl;
            return;
        }
        data[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "���� ����!" << endl;
            return;
        }
        top--;
    }

    char peek() {
        if (isEmpty()) {
            cout << "���� ����!" << endl;
            return '\0';
        }
        return data[top];
    }

    void print() {
        if (isEmpty()) {
            cout << "���� ����!" << endl;
            return;
        }
        for (int i = 0; i <= top; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // ������� ��� �������� �������� �� ������� (������������� ��� �����)
    void erase(int index) {
        if (index < 0 || index > top) {
            cout << "�������� ������!" << endl;
            return;
        }

        // �������� ��� �������� ����� ������� �� ���� ������� �����
        for (int i = index; i < top; ++i) {
            data[i] = data[i + 1];
        }
        top--;
    }

    // ������� ��� ���������� K ��������� ����� ���������� ������� (������������� ��� �����)
    void addKElementsAfter(int index, int K, char value) {
        if (index < 0 || index > top || isFull() || top + K >= MAX_SIZE) {
            cout << "�������� ��������� ��� ����������!" << endl;
            return;
        }

        // �������� ��������, ����� ���������� ����� ��� ����� ���������
        for (int i = top; i > index; --i) {
            data[i + K] = data[i];
        }

        // ��������� ����� ��������
        for (int i = 1; i <= K; ++i) {
            data[index + i] = value;
        }

        top += K;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    int index;

    Stack st;
    st.push('a');
    st.push('b');
    st.push('c');
    st.push('d');

    cout << "�������� ����: ";
    st.print();

    // ������� ������� � �������� 2
    cout << "������� ����� �������, ������� ���� ������:" << endl;
    cin >> index;
    st.erase(index);
    cout << "���� ����� �������� �������� � �������� " << index << ":" << endl;
    st.print();

    // ��������� 3 �������� 'x' ����� �������� � �������� 1
    int number;
    char ch;

    cout << "������� ������ ����� �������� ����� ����������� ����� �������:" << endl;
    cin >> index;

    cout << "������� ���������� ����������� ��������:" << endl;
    cin >> number;

    cout << "������� ������:" << endl;
    cin >> ch;

    st.addKElementsAfter(index, number, ch);
    cout << "���� ����� ����������: " << endl;
    st.print();

    return 0;
}