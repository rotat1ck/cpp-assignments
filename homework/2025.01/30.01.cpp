#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void one() {
    for (int i = 1; i <= 5; ++i) {
        cout << i << "\t" << pow(i, 2) << endl;
    }
}

double two(int n) {
    double result = 0;
    double sinsum = 0;

    for (int i = 1; i <= n; ++i) {
        sinsum += sin(i * M_PI / 180);
        result += 1 / sinsum;
    }
    return result;
}

void three(double h, double a, double b) {
    cout << setprecision(3);
    for (double x = a; x <= b; x += h) {
        double ln_x = log(x);
        double cot_ln_x = 1 / tan(ln_x);
        double result = cot_ln_x * cot_ln_x;
        cout << result << "\n";
    }
}

void four(int height, int width, char symbol) {
    if (height % 2 == 0 || width % 2 == 0) {
        cout << "Неверный ввод";
        return;
    }
    int gapsize = (width - 1) / 2;
    string gap(gapsize, ' ');
    cout << gap << symbol << gap << endl;
    for (int i = 1; i <= (height - 3) / 2; ++i) {
        gapsize = (width - 1) / 2 - i;
        string gap(gapsize, ' ');
        string inBetween(width - (gapsize * 2) - 2, ' ');
        cout << gap << symbol << inBetween << symbol << endl;
    }
    gap = string(width - 2, ' ');
    cout << symbol << gap << symbol << endl;
    for (int i = 1; i <= (height - 3) / 2; ++i) {
        gapsize = i;
        string gap(gapsize, ' ');
        string inBetween(width - (gapsize * 2) - 2, ' ');
        cout << gap << symbol << inBetween << symbol << endl;
    }
    gap = string((width - 1) / 2, ' ');
    cout << gap << symbol << gap << endl; 
}

int main() {
    four(13, 13, '#');
}