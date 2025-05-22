#include <iostream>
#include <clocale>
#include <windows.h>
using namespace std;

struct Set {
    char* elements;
    int capacity;
    int size;

    Set() {
        capacity = 10;
        elements = new char[capacity];
        size = 0;
    }

    ~Set() {
        delete[] elements;
    }

    void resize() {
        capacity *= 2;
        char* newElements = new char[capacity];
        for (int i = 0; i < size; ++i) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }

    bool contains(char data) {
        for (int i = 0; i < size; ++i) {
            if (elements[i] == data) {
                return true;
            }
        }
        return false;
    }

    void insert(char data) {
        if (contains(data)) return; // Множество содержит только уникальные элементы

        if (size >= capacity) {
            resize();
        }
        elements[size++] = data;
    }

    void erase(char data) {
        for (int i = 0; i < size; ++i) {
            if (elements[i] == data) {
                // Сдвигаем все элементы после удаляемого на одну позицию влево
                for (int j = i; j < size - 1; ++j) {
                    elements[j] = elements[j + 1];
                }
                size--;
                return;
            }
        }
    }

    void eraseAt(int index) {
        if (index < 0 || index >= size) return;

        for (int j = index; j < size - 1; ++j) {
            elements[j] = elements[j + 1];
        }
        size--;
    }

    char getAt(int index) {
        if (index < 0 || index >= size) return '\0';
        return elements[index];
    }

    void insertAfter(int index, char data) {
        if (index < 0 || index >= size || contains(data)) return;

        if (size >= capacity) {
            resize();
        }

        // Сдвигаем элементы вправо, начиная с позиции index+1
        for (int i = size; i > index + 1; --i) {
            elements[i] = elements[i - 1];
        }

        elements[index + 1] = data;
        size++;
    }

    void addKElementsAfter(int index, int K, char data) {
        if (index < 0 || index >= size || K <= 0) return;

        for (int i = 0; i < K; ++i) {
            // Для каждого нового элемента проверяем, что он уникален
            char newData = data;
            if (contains(newData)) {
                // Если элемент уже есть, модифицируем его (например, добавляем '_')
                newData = '_';
                while (contains(newData)) {
                    newData++;
                }
            }
            insertAfter(index + i, newData);
        }
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    int index;

    Set mySet;
    mySet.insert('a');
    mySet.insert('b');
    mySet.insert('c');
    mySet.insert('d');

    cout << "Исходное множество: ";
    mySet.print();

    // Удаляем элемент с индексом 2
    cout << "Введите номер индекса, который надо убрать:" << endl;
    cin >> index;
    mySet.eraseAt(index);
    cout << "Множество после удаления элемента с индексом " << index << ":" << endl;
    mySet.print();

    // Добавляем элементы после указанного индекса
    int number;
    char ch;

    cout << "Введите индекс после которого будет добавляться новые символы:" << endl;
    cin >> index;

    number=1;

    cout << "Введите символ:" << endl;
    cin >> ch;

    mySet.addKElementsAfter(index, number, ch);
    cout << "Множество после добавления: " << endl;
    mySet.print();

    return 0;
}