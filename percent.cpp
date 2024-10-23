#include <iostream>
#include <cmath>
using namespace std;

void getvalue(double *x, double* y, double* p ) {

    double a = (*x/100)**p;
    double b = ((*y/100)**p) + ((a-(int)a)* 100);

    cout << a << " " << b << " проценты" << endl;
    if (b >= 100) {
        a += 1;
        b -= 100;
    }

    *x += (int)a;
    *y += (int)b;
}

int main() {
    double p,x,y;
    double a, b;
    int z;

    cin >> p >> x >> y >> z;

    for (int i = 1; i <= z; ++i) {
        getvalue(&x, &y, &p);
        cout << x << " " << y << endl;
    }
    if (p == 0) {
        cout << (int)x << " " << (int)y;
        return 0;
    }
    
    while (y >= 100) {
        x += 1;
        y -= 100;
    }
    cout << (int)x << " " << (int)y;
    

    return 0;
}