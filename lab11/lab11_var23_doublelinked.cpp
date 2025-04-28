#include <iostream>
#include <clocale>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* prev = nullptr; // ��������� �� ���������� �������
    Node* next = nullptr; // ��������� �� ��������� �������

    void addData(char Data) {
        data = Data;
    }
};

struct list {
    Node* head = nullptr;
    Node* tail = nullptr;

    // ���������� �������� � ����� ������
    void push_back(char data) {
        Node* node = new Node;
        node->addData(data);
        if (head == nullptr) {
            head = tail = node; // ���� ������ ����, head � tail ��������� �� ����� �������
        }
        else {
            node->prev = tail; // ����� ������� ��������� �� ������� tail
            tail->next = node; // ������� tail ��������� �� ����� �������
            tail = node;       // ����� ������� ���������� tail
        }
    }

    // ���������� �������� � ������ ������
    void push_front(char data) {
        Node* node = new Node;
        node->addData(data);
        if (head == nullptr) {
            head = tail = node; // ���� ������ ����, head � tail ��������� �� ����� �������
        }
        else {
            node->next = head; // ����� ������� ��������� �� ������� head
            head->prev = node; // ������� head ��������� �� ����� �������
            head = node;       // ����� ������� ���������� head
        }
    }

    // �������� �������� �� ������ ������
    void pop_front() {
        if (head == nullptr) return; // ���� ������ ����, ������ �� ������
        if (head == tail) {          // ���� � ������ ������ ���� �������
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* node = head;       // ���������� ������� head
        head = head->next;       // ���������� head �� ��������� �������
        head->prev = nullptr;    // ����� head �� ����� ����������� ��������
        delete node;             // ������� ������ head
    }

    // �������� �������� �� ����� ������
    void pop_back() {
        if (tail == nullptr) return; // ���� ������ ����, ������ �� ������
        if (head == tail) {          // ���� � ������ ������ ���� �������
            delete tail;
            head = tail = nullptr;
            return;
        }
        Node* node = tail;       // ���������� ������� tail
        tail = tail->prev;       // ���������� tail �� ���������� �������
        tail->next = nullptr;    // ����� tail �� ����� ���������� ��������
        delete node;             // ������� ������ tail
    }

    // ��������� �������� �� �������
    Node* getAt(int k) {
        if (k < 0) return nullptr;

        Node* node = head;
        int n = 0;
        while (node && n != k) {
            node = node->next;
            n++;
        }
        return node;
    }

    // ������� �������� ����� �������� � �������� k
    void insert(int k, char data) {
        Node* left = getAt(k);
        if (left == nullptr) return;

        Node* node = new Node;
        node->addData(data);

        node->next = left->next; // ����� ������� ��������� �� ��������� ������� left
        node->prev = left;       // ����� ������� ��������� �� left
        if (left->next) {
            left->next->prev = node; // ��������� ������� left ��������� �� ����� �������
        }
        left->next = node; // Left ��������� �� ����� �������

        if (left == tail) tail = node; // ���� left ��� tail, ����� ������� ���������� tail
    }

    // �������� �������� � �������� k
    void erase(int k) {
        if (k < 0) return;
        if (k == 0) {
            pop_front();
            return;
        }

        Node* node = getAt(k);
        if (node == nullptr) return;

        if (node->prev) {
            node->prev->next = node->next; // ���������� ������� ��������� �� ���������
        }
        if (node->next) {
            node->next->prev = node->prev; // ��������� ������� ��������� �� ����������
        }
        if (node == tail) tail = node->prev; // ���� ��������� ������� ��� tail, ��������� tail
        delete node;
    }

    // ����� ������
    void print() {
        Node* node = head;
        while (node) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

    // ���������� K ��������� ����� �������� � �������� k
    void addKElementsAfter(int k, int K, char data) {
        Node* node = getAt(k);
        if (node == nullptr) return;

        for (int i = 0; i < K; ++i) {
            Node* newNode = new Node;
            newNode->addData(data);

            newNode->next = node->next; // ����� ������� ��������� �� ��������� ������� node
            newNode->prev = node;       // ����� ������� ��������� �� node
            if (node->next) {
                node->next->prev = newNode; // ��������� ������� node ��������� �� ����� �������
            }
            node->next = newNode; // Node ��������� �� ����� �������

            if (node == tail) tail = newNode; // ���� node ��� tail, ����� ������� ���������� tail
            node = newNode; // ���������� node �� ����� ������� ��� ��������� ��������
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    int index;

    list lst;
    lst.push_back('a');
    lst.push_back('b');
    lst.push_back('c');
    lst.push_back('d');

    cout << "�������� ������: ";
    lst.print();

    // ������� ������� � �������� 2
    cout << "������� ����� �������, ������� ���� ������:" << endl;
    cin >> index;
    lst.erase(index);
    cout << "������ ����� �������� �������� � �������� " << index << ":" << endl;
    lst.print();

    // ��������� K ��������� ����� �������� � �������� k
    int number;
    char ch;

    cout << "������� ������ ����� �������� ����� ����������� ����� �������:" << endl;
    cin >> index;

    cout << "������� ���������� ����������� ��������:" << endl;
    cin >> number;

    cout << "������� ������:" << endl;
    cin >> ch;

    lst.addKElementsAfter(index, number, ch);
    cout << "������ ����� ����������: " << endl;
    lst.print();

    return 0;
}