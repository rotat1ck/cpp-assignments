#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> abc;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        abc.push_back(temp);
    }

    cout << abc[4];
}