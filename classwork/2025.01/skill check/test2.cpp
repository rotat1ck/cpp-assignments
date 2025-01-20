#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int size;
    vector<int> nums;
    cout << "Введите размер массива: ";
    cin >> size;
    cout << "Введите числа в массив: ";
    for (int i = 0; i < size; ++i) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end());

    cout << nums[size - 3];

    // 🥨
}