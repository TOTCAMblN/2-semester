#include <iostream>
#include <clocale>
#include <windows.h>
using namespace std;

const int MAX_SIZE = 100; // Максимальный размер стека

struct Stack {
    char data[MAX_SIZE];
    int top = -1; // Индекс вершины стека

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(char value) {
        if (isFull()) {
            cout << "Стек переполнен!" << endl;
            return;
        }
        data[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Стек пуст!" << endl;
            return;
        }
        top--;
    }

    char peek() {
        if (isEmpty()) {
            cout << "Стек пуст!" << endl;
            return '\0';
        }
        return data[top];
    }

    void print() {
        if (isEmpty()) {
            cout << "Стек пуст!" << endl;
            return;
        }
        for (int i = 0; i <= top; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // Функция для удаления элемента по индексу (нестандартная для стека)
    void erase(int index) {
        if (index < 0 || index > top) {
            cout << "Неверный индекс!" << endl;
            return;
        }

        // Сдвигаем все элементы после индекса на одну позицию влево
        for (int i = index; i < top; ++i) {
            data[i] = data[i + 1];
        }
        top--;
    }

    // Функция для добавления K элементов после указанного индекса (нестандартная для стека)
    void addKElementsAfter(int index, int K, char value) {
        if (index < 0 || index > top || isFull() || top + K >= MAX_SIZE) {
            cout << "Неверные параметры для добавления!" << endl;
            return;
        }

        // Сдвигаем элементы, чтобы освободить место для новых элементов
        for (int i = top; i > index; --i) {
            data[i + K] = data[i];
        }

        // Вставляем новые элементы
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

    cout << "Исходный стек: ";
    st.print();

    // Удаляем элемент с индексом 2
    cout << "Введите номер индекса, который надо убрать:" << endl;
    cin >> index;
    st.erase(index);
    cout << "Стек после удаления элемента с индексом " << index << ":" << endl;
    st.print();

    // Добавляем 3 элемента 'x' после элемента с индексом 1
    int number;
    char ch;

    cout << "Введите индекс после которого будет добавляться новые символы:" << endl;
    cin >> index;

    cout << "Введите количество добавленных символов:" << endl;
    cin >> number;

    cout << "Введите символ:" << endl;
    cin >> ch;

    st.addKElementsAfter(index, number, ch);
    cout << "Стек после добавления: " << endl;
    st.print();

    return 0;
}