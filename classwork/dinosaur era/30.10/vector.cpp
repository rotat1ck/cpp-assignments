#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    vector<int> numlist;

    int size;
    cout << "Введите кол-во элелентов вектора: ";
    cin >> size;

    for (int i = 0; i < size; ++i) {
        int num;
        cin >> num;
        numlist.push_back(num);
    }

    for (auto elem : numlist) {
        cout << elem << " ";
    }

    for (auto p = numlist.begin(); p != numlist.end(); ++p) {
        auto elem = *p;
        cout << elem << " ";
    }
    
    return 0;
}