#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vecs;

    for (int i = 0; i < n; ++i) {
        vector<int> vec;
        for (int j = 0; j < m; ++j) {
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }
        vecs.push_back(vec);
    }

    int request;

    cin >> request;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j ) {
            int counter = 0;
            if (vecs[i][j] == 0) {
                bool isGood = true;
                for (int k = j; k < m; ++k) {
                    if (vecs[i][k] != 0 && counter < request) {
                        isGood = false;
                    } else if (vecs[i][k] == 0){
                        counter++;
                    }
                }
                if (counter >= request && isGood) {
                    cout << i+1;
                    return 0;
                } 
            } 
        }
    }
    cout << 0;
}