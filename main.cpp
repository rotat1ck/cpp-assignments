#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

system("chcp 65001");
system("cls");

void one();


int main() {
    cout << "Выберите номер задания от 1 до 7: ";
    while (true) {
        if (kbhit()) {
            switch(getch()) {
                case 49:
                    cout << 1 << endl;
                    one();
                    break;
            }
        }
    }

}

void one() {
    int a,b;
    system("cls");
    cout << "Введите два числа: ";
    cin >> a >> b;
    
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }

    cout << "Наибольший общий делитель: " << a << endl;
    main();
}