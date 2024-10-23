#include <iostream>
#include <cmath>
using namespace std;

void getvalue(double *x, double* y, double* p ) {

    double a = (*x/100)**p;
    double b = ((*y/100)**p) + ((a-(int)a)* 100);

<<<<<<< HEAD
    cout << a << " " << b << " проценты" << endl;
=======
>>>>>>> 3a0cd425b5ed7c7dc4de5e6d948fc85ac0549759
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
<<<<<<< HEAD
        cout << x << " " << y << endl;
=======
>>>>>>> 3a0cd425b5ed7c7dc4de5e6d948fc85ac0549759
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