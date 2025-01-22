#include <iostream>
#include <vector>
#include <algorithm>
#include <rotatick/timer.hpp>

using namespace std;

template <typename t>
class algo {
private:
    vector<t> arr;
public:
    algo(vector<t> _arr) {
        arr = _arr;
    }
    vector<t> sorted() {
        vector<t> temp = arr;
        sort(temp.begin(), temp.end());
        return temp;
    }
    vector<t> combine(vector<t> _arr) {
        vector<t> temp = arr;
        for (auto item : _arr) {
            temp.push_back(item);
        }
        return temp;
    }
};

int main() {
    algo one(vector<int>{9, 7, 8, 5 ,22, 0, 1});
    for (auto item : one.sorted()) {
        cout << item << " ";
    }
    cout << endl;

    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto item : one.combine(nums)) {
        cout << item << " ";
    }
    
    return 0;
}