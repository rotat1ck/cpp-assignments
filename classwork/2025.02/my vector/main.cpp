#include <iostream>

using namespace std;

template <typename T>
class VectorType {
private:
    int cap;
    int size;
    T* data;
public:
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

    void Append(T elem) {
        if (size == cap) {
            cap *= 2;
            T* temp = data;
            data = new T[cap];
            for (int i = 0; i < size; ++i) {
                data[i] = temp[i];
            }
            delete[] temp;
            size++;
            data[size - 1] = elem;
        } else {
            size++;
            data[size - 1] = elem;
        }
    }

    void Pop(int index) {
        if (index > size) {
            return;
        } else {
            for (int i = index; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            data[size - 1] = 0;
            size--;
        }
    }

    int Size() {
        return size;
    }
};

int main() {
    VectorType<int> vec = {1, 2, 3, 4, 5};
    VectorType<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // VectorType<int> vec2(vec);
    // cout << vec[1];

    VectorType<int> vec3 = {1, 2, 3};
    
    // vec3.Append(4);
    // vec3.Pop(2);
    // vec3.Append(8);
    // for (int i = 0; i < vec3.Size(); ++i) {
    //     cout << vec3[i] << " ";
    // }

    for (int i = 0; i < 100; ++i) {
        vec3.Append(i);
    }

    for (int i = 0; i < vec3.Size(); ++i) {
        cout << vec3[i] << " ";
    }
    
    return 0;
}