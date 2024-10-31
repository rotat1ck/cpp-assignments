#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int size;
    vector<int> vec;

    cout << "Введите длину вектора: ";
    cin >> size;

    cout << "Введите числа: ";

    for (int i = 0; i < size; ++i) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end());
    auto pos = unique(vec.begin(), vec.end());

    vec.erase(pos, vec.end());
    for (auto elem : vec) {
        cout << elem << " ";
    }
}