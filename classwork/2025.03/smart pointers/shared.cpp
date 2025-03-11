#include <iostream>
#include <memory>
#include <rotatick/list.cpp>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class b;

class a {
public:
    shared_ptr<b> a_ptr;

    ~a() {
        cout << "a desctructor" << endl;
    }
};

class b {
public:
    weak_ptr<a> b_ptr;

    ~b() {
        cout << "b desctructor" << endl;
    }
};

int main() {
    shared_ptr<list<int>> p1 = make_shared<list<int>>();

    p1->append(5);
    p1->append(10);
    p1->append(15);

    try {
        shared_ptr<a> aPtr = make_shared<a>();
        shared_ptr<b> bPtr = make_shared<b>();

        aPtr->a_ptr = bPtr;
        bPtr->b_ptr = aPtr;
    } catch (exception& ex) {
        cout << ex.what() << endl;
    }

    vector<int> vec = {9, 1, 56, 107, 101, 167, 90};

    auto f = [&] (int sum, int n) {
        if (n % 2 == 0) {
            return sum + n;
        }
        return sum;
    };

    auto sortFunc = [&](int a, int b) {
        if (a < 100 && b < 100) {
            return a < b;
        }
        return a > b;
    };

    cout << accumulate(vec.begin(), vec.end(), 0, f) << endl;

    sort(vec.begin(), vec.end(), sortFunc);

    for (auto it : vec) {
        cout << it << " ";
    }
}