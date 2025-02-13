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
    int size = 0;

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
        
        throw "Index out of bounds";
    }

    list& operator=(initializer_list<t> init) {
        for (auto it : init) {
            append(it);
        }
        return *this;
    }

    list() { first = nullptr; last = nullptr; }

    list(int size) {
        first = nullptr;
        last = nullptr;
        for (int i = 0; i < size; ++i) {
            append(static_cast<t>(0));
        }
    }

    list(int size, t data) {
        first = nullptr;
        last = nullptr;
        for (int i = 0; i < size; ++i) {
            append(data);
        }
    }

    list(list& toCopy) {
        first = nullptr;
        last = nullptr;
        if (toCopy.first != nullptr) {
            object* ptr = toCopy.first;
            while (ptr != nullptr) {
                append(ptr->data);
                ptr = ptr->next;
            }
        } else {
            throw "Cannot copy empty list";
        }
    }

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
        size++;
    }

    void add_front(t data) {
        object* obj = new object(data);
        obj->next = first;
        first = obj;
        size++;
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

    object* find(int index) {
        if (index < 0 || index >= size) {
            throw "Index out of bounds";
        }
        object* ptr = first;
        int temp = 0;
        while (ptr != nullptr && temp < index) {
            temp++;
            ptr = ptr->next;
        }
        return ptr;
    }

    void pop(int index) {
        if (index < 0 || index >= size) {
            throw "Index out of bounds";
        }

        object* ptr = find(index);
        
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
        size--;
    }

    void swap(int index1, int index2) {
        if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size) {
            throw "Index out of bounds";
        } else if (index1 == index2) {
            return;
        } 

        object* ptr1 = find(index1);
        object* ptr2 = find(index2);
        
        t temp = ptr1->data;
        ptr1->data = ptr2->data;
        ptr2->data = temp;
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

        list<int> l3(10);
        l3.print();

        list<int> l4(l2);
        l4.print();

        list<string> l5(5, "abc");
        l5.print();

        list<int> l6 = {1, 2, 3, 4};
        l6.swap(0, 3);
        l6.print();
    } catch (const char* ex) {
        cout << "Error: " << ex << endl;
    }
}