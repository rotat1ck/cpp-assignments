#include <iostream>
using namespace std;
int main() {
    int starta, startb, a, b;
    cin >> starta >> startb >> a >> b;

    if (starta < a) {
        if (startb < b) {
            if (a - starta == 1 && b - startb == 2) {
                cout << "YES";
            } else if (a - starta == 2 && b - startb == 1){
                cout << "YES";
            } else {
                cout << "NO";
            }
        } else if (startb > b) {
            if (a - starta == 2 && startb - b == 1) {
                cout << "YES";
            } else if (a - starta == 1 && startb - b == 2){
                cout << "YES";
            } else {
                cout << "NO";
            }
        }
    } else if (starta > a) {
        if (startb < b) {
            if (starta - a  == 1 && b - startb == 2) {
                cout << "YES";
            } else if (starta - a == 2 && b - startb == 1) {
                cout << "YES";
            } else {
                cout << "NO";
            }
        } else if (startb > b) {
            if (starta - a == 2 && startb - b == 1) {
                cout << "YES";
            } else if (starta - a == 1 && startb - b == 2) {
                cout << "YES";
            } else {
                cout << "NO";
            }
        }
    } else {
        cout << "NO";
    }
    return 0;
}