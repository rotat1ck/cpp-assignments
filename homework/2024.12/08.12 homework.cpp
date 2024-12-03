#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

struct rat {
    double speed;
    double position;
    string size;
    string name;
    int age;
};

rat createRat() {
    double speed;
    double position;
    string size;
    string name;
    int age;
    cout << "Введите скорость: ";
    cin >> speed;
    cout << "Введите позицию: ";
    cin >> position;
    cout << "Введите размер: ";
    getline(cin, size);
    cout << "Введите имя: ";
    getline(cin, name);
    cout << "Введите возраст: ";
    cin >> age;

    return rat{speed, position, size, name, age};
}

void changePosition(rat &rat) {
    int ratSpeed = rat.speed;

    std::default_random_engine generator;
    std::normal_distribution<double> distribution(ratSpeed, 3);
    
    rat.position += abs(distribution(generator));
}

void changeNameSpeed(rat &rat) {
    string input;
    cout << "Введите новое имя крысы: ";
    getline(cin, input);
    rat.name = input;

    cout << "Введите новую скорость крысы: ";
    cin >> rat.speed;
}


int main() {
    rat rat1 = {
        .speed = 10, 
        .position = 0,
        .size = "Средняя",
        .name = "Крыска",
        .age = 4
    };

    rat rat2 = {
        .speed = 5, 
        .position = 7,
        .size = "Большая",
        .name = "Крыса",
        .age = 1
    };

    changePosition(rat1);

    cout << "Новая позиция крысы: " << rat1.position << endl;

    rat newrat = shuffle(rat1, rat2);

    cout << "Новая крыса: " << endl;
    cout << newrat.speed << " " << newrat.position << " " << newrat.size << " " <<  newrat.name << " " << newrat.age;

    // 🥨
}