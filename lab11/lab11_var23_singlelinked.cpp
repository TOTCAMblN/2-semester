#include <iostream>
#include <clocale>
#include <windows.h>;
using namespace std;

struct Node {
    char data;
    Node* next_ptr;

    void addData(char Data) {
        data = Data;
        next_ptr = nullptr;
    }
};

struct list {
    Node* head = nullptr;
    Node* tail = nullptr;

    void push_back(char data) {
        Node* node = new Node;
        node->addData(data);
        if (head == nullptr) head = node;
        if (tail != nullptr) tail->next_ptr = node;
        tail = node;
    }

    void push_front(char data) {
        Node* node = new Node;
        node->addData(data);
        node->next_ptr = head;
        head = node;
        if (tail == nullptr) tail = node;
    }

    void pop_front() {
        if (head == nullptr) return;
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
            return;
        }
        Node* node = head;
        head = node->next_ptr;
        delete node;
    }

    void pop_back() {
        if (tail == nullptr) return;
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
            return;
        }
        Node* node = head;
        while (node->next_ptr != tail) {
            node = node->next_ptr;
        }
        delete tail;
        tail = node; // Теперь tail указывает на предпоследний узел
        tail->next_ptr = nullptr;
    }

    Node* getAt(int k) {
        if (k < 0) return nullptr;

        Node* node = head;
        int n = 0;
        while (node && n != k) {
            node = node->next_ptr;
            n++;
        }
        return node;
    }

    void insert(int k, char data) {
        Node* left = getAt(k);
        if (left == nullptr) return;

        Node* node = new Node;
        node->addData(data);
        node->next_ptr = left->next_ptr;
        left->next_ptr = node;

        if (left == tail) tail = node;
    }

    void erase(int k) {
        if (k < 0) return;
        if (k == 0) {
            pop_front();
            return;
        }

        Node* left = getAt(k - 1);
        if (left == nullptr || left->next_ptr == nullptr) return;

        Node* node = left->next_ptr;
        Node* right = node->next_ptr;
        left->next_ptr = right;
        if (node == tail) tail = left;
        delete node;
    }

    void print() {
        Node* node = head;
        while (node) {
            cout << node->data << " ";
            node = node->next_ptr;
        }
        cout << endl;
    }

    void addKElementsAfter(int k, int K, char data) {
        Node* node = getAt(k);
        if (node == nullptr) return;

        for (int i = 0; i < K; ++i) {
            Node* newNode = new Node;
            newNode->addData(data);
            newNode->next_ptr = node->next_ptr;
            node->next_ptr = newNode;
            if (node == tail) tail = newNode;
            node = newNode;
        }
    }
};

int main(){
    setlocale(LC_ALL, "Russian");

    int index;

    list lst;
    lst.push_back('a');
    lst.push_back('b');
    lst.push_back('c');
    lst.push_back('d');

    cout << "Исходный список: ";
    lst.print();

    // Удаляем элемент с индексом 2
    cout << "Введите номер индекса, который надо убрать:" << endl;

    cin >> index;
    lst.erase(index);
    cout << "Список после удаления элемента с индексом " << index << ":" << endl;
    lst.print();

    // Добавляем 3 элемента 'x' после элемента с индексом 1
    int number;
    char ch;

    cout << "Введите индекс после которого будет добавляться новые символы:" << endl;

    cin >> index;

    cout << "Введите количество добавленных символов:" << endl;

    cin >> number;

    cout << "Введите символ:" << endl;

    cin >> ch;

    lst.addKElementsAfter(index, number, ch);
    cout << "Список после добавления : " << endl;
    lst.print();

    return 0;
}