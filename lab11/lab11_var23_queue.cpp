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
    // ���������� �������� � ����� �������
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

    // �������� �������� �� ������ �������
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

    // ��������� �������� �� ������� (������������� �������� ��� �������)
    Node* getAt(int k) {
        if (k < 0 || k >= size) return nullptr;

        Node* node = head;
        for (int i = 0; i < k; ++i) {
            node = node->next_ptr;
        }
        return node;
    }

    // �������� �������� �� ������� (������������� �������� ��� �������)
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

    // ���������� K ��������� ����� �������� � �������� k (������������� �������� ��� �������)
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

    // ����� ���� ��������� �������
    void print() {
        Node* node = head;
        while (node) {
            cout << node->data << " ";
            node = node->next_ptr;
        }
        cout << endl;
    }

    // ���������� ��� ������������ ������
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

    cout << "�������� �������: ";
    q.print();

    // ������� ������� � �������� 2
    cout << "������� ����� �������, ������� ���� ������:" << endl;
    cin >> index;
    q.erase(index);
    cout << "������� ����� �������� �������� � �������� " << index << ":" << endl;
    q.print();

    // ��������� �������� ����� ���������� �������
    int number;
    char ch;

    cout << "������� ������ ����� �������� ����� ����������� ����� �������:" << endl;
    cin >> index;

    cout << "������� ���������� ����������� ��������:" << endl;
    cin >> number;

    cout << "������� ������:" << endl;
    cin >> ch;

    q.addKElementsAfter(index, number, ch);
    cout << "������� ����� ����������: " << endl;
    q.print();

    return 0;
}