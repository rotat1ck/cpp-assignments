#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <conio.h>

using namespace std;

struct cat {
    string name;
    int age;
    string color;
    string breed;
};

// инициализация переменных и стартовой функции
void start();
cat recentCat;
vector<cat> savedCats;

// чтение последней введеной кошки
ostream &operator<<(ostream &os, cat &cat) {
    os << "Имя:\t" << cat.name << "\nЛет:\t" << cat.age << "\nЦвет:\t" << cat.color << "\nПорода:\t" << cat.breed << "\n\n";
    return os;
}

// чтение вектора кошек
ostream &operator<<(ostream &os, vector<cat> &cats) {
    os << "Вектор сохраненных кошек: " << endl;
    for (auto cat : cats) {
        os << "Имя:\t" << cat.name << "\nЛет:\t" << cat.age << "\nЦвет:\t" << cat.color << "\nПорода:\t" << cat.breed << "\n\n";
    }
    return os;
}

// ввод кошки
istream &operator>>(istream &is, cat &cat) {
    is >> cat.name >> cat.age >> cat.color >> cat.breed;
    return is;
}

// создание кошки и запись в вектор
void createCat(vector<cat> &savedCats, cat &recentCat) {
    system("cls");

    cout << "Создание записи о кошке\n" << "Шаблон: {ИМЯ} {ВОЗРАСТ} {ЦВЕТ} {ПОРОДА}" << endl;
    cat newCat;
    cin >> newCat;
    recentCat = newCat;
    cout << "Запись создана, добавить её в список? (y)" << endl;
    
    char ch = _getch();
    if (tolower(ch) == 'y') {
        savedCats.push_back(newCat);
        cout << "Запись сохранена" << endl;
    } else {
        cout << "Запись не сохранена" << endl;
    }

    start();
}

// стартовая функция
void start() {
    vector<char> allowedKeys= {'1', '2', '3'};
    cout << "Выберете функцию: \n" << "1. Создание кошки\n2. Последняя кошка\n3. Список сохраненных кошек" << endl;
    char ch;
    while(true) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 27) {
                exit(0);
            } else if (find(allowedKeys.begin(), allowedKeys.end(), ch) != allowedKeys.end()) {
                switch(ch) {
                    case '1': {
                        createCat(savedCats, recentCat);
                        break;
                    } case '2': {
                        system("cls");
                        cout << "Последняя введеная кошка: \n" << recentCat;
                        break;
                    } case '3': {
                        system("cls");
                        cout << savedCats;
                        break;
                    }
                }
                start();
            }
            system("cls");
            cout << "Некорректный ввод\n";
            start();
        }
    }
}

int main() {
    system("chcp 65001");
    system("cls");
    cout << "ESC - Закрыть программу" << endl;
    start();

    // 🥨
}