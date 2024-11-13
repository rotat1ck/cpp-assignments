#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> vec;

    int size;
    cin >> size;
    bool isSimetrical = true;
    for (int i = 0; i < size; ++i) {
        vector<int> v1;
        int counter = 0;
        for (int j = 0; j < size; ++j) {
            int input;
            cin >> input;
            v1.push_back(input);
        }
        vec.push_back(v1);
    }

    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[i].size(); ++j) {
            if (vec[i][j] != vec[j][i]) {
                isSimetrical = false;
            }
        }
    }

    if (isSimetrical) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}