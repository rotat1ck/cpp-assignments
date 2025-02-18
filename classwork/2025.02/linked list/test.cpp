#include <iostream>
#include <string>

using namespace std;

template <typename T>
class List {
private:
    struct Node {
        T val;
        Node* next;
        Node* prev;

        Node(T value) : val(value), next(nullptr), prev(nullptr) {}
    };

    Node* tail = nullptr;
    Node* head = nullptr;
    int size;

public:
    List() : size(0), head(nullptr), tail(nullptr) {}

    List(int size) : size(0) {
        while (this->size != size) push_back(0);
    }

    List(int size, T value) : size(0) {
        while (this->size != size) push_back(value);
    }

    List(initializer_list<T> init) : size(0) {
        for (const auto data : init) {
            push_back(data);
        }
    }

    List& operator = (initializer_list<T> init) {
        for (const auto data : init) {
            push_back(data);
        }
        return *this;
    }
    void push_back(T value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode; 
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void print() {
        Node* newNode = head;
        for (int i = 0; i < size; i++) {
            cout << newNode->val << " ";
            newNode = newNode->next;
        }
        cout << endl;
    }


};



int main() {

    List<int> list1({ 1,4,6,4 });


    list1.print();



    return 0;
}