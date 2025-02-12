#include <iostream>

using namespace std;

template <typename t>
class list {
private:
    struct object {
        t data;
        object* prev;
        object* next;

        object(t data) {
            prev = nullptr;
            next = nullptr;
            this->data = data;
        }
    };
    object* first;
    object* last;
    int count = 0;

public:
    t& operator[](int index) {
        object* ptr = first;
        int temp = 0;
        while (ptr != nullptr && temp <=index) {
            if (temp == index) {    
                return ptr->data;
            } else {
                temp++;
                ptr = ptr->next;
            }
        }
        
        throw "Index out of range";
    }

    list& operator=(initializer_list<t> init) {
        for (auto it : init) {
            append(it);
        }
        return *this;
    }

    list() { first = nullptr; last = nullptr; }

    list(initializer_list<t> init) {
        first = nullptr;
        last = nullptr;
        for (auto it : init) {
            append(it);
        }
    }

    ~list() {
        object* ptr = first;
        while (ptr != nullptr) {
            object* next = ptr->next;
            delete ptr;
            ptr = next;
        }
    }

    void append(t data) {
        object* obj = new object(data);
        if (first == nullptr) {
            first = obj;
            last = obj;
        } else {
            last->next = obj;
            obj->prev = last;
            last = obj;
        }
        count++;
    }

    void add_front(t data) {
        object* obj = new object(data);
        obj->next = first;
        first = obj;
        count++;
    }

    void print() {
        if (first == nullptr) {
            throw "List is empty";
        } else {
            cout << "[";
            object* ptr = first;
            while (ptr->next != nullptr) {
                cout << ptr->data << ", ";
                ptr = ptr->next;
            }
            cout << ptr->data << "]" << endl;
        }
    }

    void pop(int index) {
        if (index < 0 || index >= count) {
            throw "Index out of range";
        }

        object* ptr = first;
        int temp = 0;
        while (ptr != nullptr && temp < index) {
            temp++;
            ptr = ptr->next;
        }

        if (ptr->prev == nullptr) {
            if (ptr->next != nullptr) {
                first = ptr->next;
            } else {
                first = nullptr;
                last = nullptr;
            }
        } else if (ptr->next == nullptr) {
            last = ptr->prev;
            last->next = nullptr;
        } else {
            object* prev = ptr->prev;
            object* next = ptr->next;
            prev->next = ptr->next;
            next->prev = ptr->prev;
        }

        delete ptr;
        count--;
    }
};

int main() {
    try {
        list<int> l1;
        l1.append(1);
        l1.append(4);
        l1.append(3);
        l1.append(2);
        l1.add_front(0);
        l1.print();

        // cout << l1[2];

        list<int> l2 = {5, 4, 3, 2, 1};
        l2.add_front(0);
        l2.pop(5);
        l2.print();
    } catch (const char* ex) {
        cout << "Error: " << ex << endl;
    }
}