#include <iostream>

using namespace std;

int main() 
{
    int starta, startb, a, b;
    cin >> starta >> startb >> a >> b;
    if (starta == a || startb == b) {
        if (starta == a && startb == b) {
            cout << "NO";
        } else {
            cout << "YES";
        }
    } else if (a - starta >= 1) {
        if (b - startb >= 1) {
            if ((b- startb) == (a-starta)) {
                cout << "YES";
            } else {
                cout << "NO";
            }
        } else if (startb - b >= 1) {
            if ((startb -b) == (a-starta)) {
                cout << "YES";
            } else {
                cout << "NO";
            }
        } else {
            cout << "NO";
        }
    } else if (starta - a >= 1) {
        if (b - startb >= 1) {
            if ((b- startb) == (starta - a)) {
                cout << "YES";
            } else {
                cout << "NO";
            }
        } else if (startb - b >= 1) {
            if ((startb -b) == (starta - a)) {
                cout << "YES";
            } else {
                cout << "NO";
            }
        } else {
            cout << "NO";
        }
    } else {
        cout << "NO";
    }

}