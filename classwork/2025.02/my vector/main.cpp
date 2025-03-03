#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class VectorType {
private:
    class iterator {
    private:
        T* ptr;
    public:
        iterator() : ptr(nullptr) {};
        iterator(T* m_ptr = nullptr) : ptr(m_ptr) {};

        iterator& operator =(const iterator&) = default; 

        T& operator *() {return *ptr;}

        iterator& operator ++(int) {
            iterator tmp(*this);
            ++ptr;
            return tmp;
        }

        iterator& operator ++() {
            ++ptr;
            return *this;
        }

        iterator& operator --(int) {
            iterator tmp(*this);
            --ptr;
            return tmp;
        }

        iterator& operator --() {
            --ptr;
            return *this;
        }

        iterator& operator -(ptrdiff_t p) {
            ptr -= p;
            return *this;
        }

        iterator& operator +=(ptrdiff_t p) {
            ptr += p;
            return *this;
        }
    };

    int cap;
    int size;
    T* data;
public:
    VectorType() {
        cap = 1;
        size = 0;
        data = new T[cap];
    }

    VectorType(int size) {
        cap = size * 2;
        this->size = size;
        data = new T[cap];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }
    
    VectorType(initializer_list<T> init) {
        cap = init.size() * 2;
        size = init.size();
        data = new T[cap];
        int i = 0;
        for (auto it = init.begin(); it != init.end(); it++) {
            data[i++] = *it;
        }
    }

    VectorType(const VectorType& other) {
        cap = other.cap;
        size = other.size;
        data = new T[cap];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    ~VectorType() {
        delete[] data;
    }

    T &operator [](int index) {
        if (index< size) {
            return data[index];
        }
        return data[size - 1];
    }

    VectorType &operator =(initializer_list<T> init) {
        cap = init.size() * 2;
        size = init.size();
        data = new T[cap];
        int i = 0;
        for (auto it = init.begin(); it != init.end(); it++) {
            data[i++] = *it;
        }
        return *this;
    }

    T* Begin() {
        return data;
    }

    T* End() {
        return data + size;
    }

    void expandCap() {
        cap *= 2;
        T* temp = data;
        data = new T[cap];
        for (int i = 0; i < size; ++i) {
            data[i] = temp[i];
        }
        delete[] temp;
    }

    void Append(T elem) {
        if (size == cap) {
            expandCap();
        }
        size++;
        data[size - 1] = elem;
    }

    void Pop(int index) {
        if (index > size) {
            return;
        } else {
            if (size == cap) {
                expandCap();
            }
            for (int i = index; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            data[size - 1] = 0;
            size--;
        }
    }

    void Insert(int index, T elem) {
        if (index > size) {
            return;
        } else {
            if (size == cap) {
                expandCap();
            }
            for (int i = size; i > index; --i) {
                data[i] = data[i - 1];
            }
            data[index] = elem;
            size++;
        }
    }

    int Size() {
        return size;
    }


};

int main() {
    VectorType<int> vec = {1, 2, 3, 4, 5};
    
    // for (int i = 0; i < 100; ++i) {
    //     vec.Append(i);
    // }

    // for (int i = 0; i < vec.Size(); ++i) {
    //     cout << vec[i] << " ";
    // }


    vec.Insert(2, 10);
    vec.Insert(2, 11);
    vec.Insert(2, 12);

    for (int i = 0; i < vec.Size(); ++i) {
        cout << vec[i] << " ";
    }

    cout << endl;
    sort(vec.Begin(), vec.End());

    for (int i = 0; i < vec.Size(); ++i) {
        cout << vec[i] << " ";
    }

    return 0;

    // 🥨
}