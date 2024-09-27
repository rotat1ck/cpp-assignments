#include <iostream>

using namespace std;

int main() {
    int starta, startb, a, b, num = 0;
    cin >> starta >> startb >> a >> b;

    if (starta <= a) {
        if ((a - starta) <= 1) {
            if (startb <= b) {
                if ((b - startb) <= 1) {
                    cout << "YES";
                } else {
                    cout << "NO";
                }
            } else {
                if ((startb - b) <= 1) {
                    cout << "YES";
                } else {
                    cout << "NO";
                }
            }
        } else {
            cout << "NO";
        }
    } else if (starta >= a) {
        if ((starta - a) <= 1) {
            if (startb <= b) {
                if ((b - startb) <= 1) {
                    cout << "YES";
                } else {
                    cout << "NO";
                }
            } else {
                if ((startb - b) <= 1) {
                    cout << "YES";
                } else {
                    cout << "NO";
                }
            }
        } else {
            cout << "NO";
        }
    }
    return 0;
}