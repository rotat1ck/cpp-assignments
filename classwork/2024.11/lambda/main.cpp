#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countChet(const vector<int> &qs) {
    return count_if(qs.begin(), qs.end(), [](int a) -> bool { return a % 2 == 0; });
}

int countN(const vector<int> &qs, int &n) {
    return count_if(qs.begin(), qs.end(), [=](int a) -> bool { return a % n == 0; });
}

void map(vector<int> &qs, int func(int, int)) {
    for (int i = 0; i < qs.size(); ++i) {
        qs[i] = func(qs[i], i);
    }
}

int main() {
    vector<int> nums{10, 23, 34, 45, 56, 147};
    for (int i : nums) { cout << i << " ";} cout << endl;
    map(nums, [](int item, int index) { return item + index;});
    for (int i : nums) { cout << i << " ";}

    // 🥨
}