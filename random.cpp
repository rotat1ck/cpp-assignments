#include <iostream>

using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;
    int field[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> field[i][j];
        }
    }

    int m1,m2;
    cin >> m1 >> m2;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == m1 || j == m2) {
                int temp = field[i][m1];
                field[i][m1] = field[i][m2];
                field[i][m2] = temp;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}
