#include <iostream>
#include <clocale>
#include <windows.h>
using namespace std;

struct Node {
    char data;
    Node* next_ptr;

    void addData(char Data) {
        data = Data;
        next_ptr = nullptr;
    }
};

class Queue {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

public:
    // Добавление элемента в конец очереди
    void enqueue(char data) {
        Node* node = new Node;
        node->addData(data);
        if (tail == nullptr) {
            head = tail = node;
        }
        else {
            tail->next_ptr = node;
            tail = node;
        }
        size++;
    }

    // Удаление элемента из начала очереди
    void dequeue() {
        if (head == nullptr) return;

        Node* temp = head;
        head = head->next_ptr;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
        size--;
    }

    // Получение элемента по индексу (нестандартная операция для очереди)
    Node* getAt(int k) {
        if (k < 0 || k >= size) return nullptr;

        Node* node = head;
        for (int i = 0; i < k; ++i) {
            node = node->next_ptr;
        }
        return node;
    }

    // Удаление элемента по индексу (нестандартная операция для очереди)
    void erase(int k) {
        if (k < 0 || k >= size) return;

        if (k == 0) {
            dequeue();
            return;
        }

        Node* prev = getAt(k - 1);
        Node* toDelete = prev->next_ptr;
        prev->next_ptr = toDelete->next_ptr;

        if (toDelete == tail) {
            tail = prev;
        }

        delete toDelete;
        size--;
    }

    // Добавление K элементов после элемента с индексом k (нестандартная операция для очереди)
    void addKElementsAfter(int k, int K, char data) {
        if (k < 0 || k >= size) return;

        Node* node = getAt(k);
        for (int i = 0; i < K; ++i) {
            Node* newNode = new Node;
            newNode->addData(data);
            newNode->next_ptr = node->next_ptr;
            node->next_ptr = newNode;

            if (node == tail) {
                tail = newNode;
            }

            node = newNode;
            size++;
        }
    }

    // Вывод всех элементов очереди
    void print() {
        Node* node = head;
        while (node) {
            cout << node->data << " ";
            node = node->next_ptr;
        }
        cout << endl;
    }

    // Деструктор для освобождения памяти
    ~Queue() {
        while (head) {
            dequeue();
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    int index;

    Queue q;
    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('c');
    q.enqueue('d');

    cout << "Исходная очередь: ";
    q.print();

    // Удаляем элемент с индексом 2
    cout << "Введите номер индекса, который надо убрать:" << endl;
    cin >> index;
    q.erase(index);
    cout << "Очередь после удаления элемента с индексом " << index << ":" << endl;
    q.print();

    // Добавляем элементы после указанного индекса
    int number;
    char ch;

    cout << "Введите индекс после которого будет добавляться новые символы:" << endl;
    cin >> index;

    cout << "Введите количество добавленных символов:" << endl;
    cin >> number;

    cout << "Введите символ:" << endl;
    cin >> ch;

    q.addKElementsAfter(index, number, ch);
    cout << "Очередь после добавления: " << endl;
    q.print();

    return 0;
}