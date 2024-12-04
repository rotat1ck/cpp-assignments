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

rat shuffle(rat &rat1, rat &rat2) {
    std::srand(std::time(0));
    
    double speedRand = 1.0 + static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX) / (2.0 - 1.0));
    double positionRand = 1.0 + static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX) / (2.0 - 1.0));
    double sizeRand = 1.0 + static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX) / (2.0 - 1.0));
    double nameRand = 1.0 + static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX) / (2.0 - 1.0));
    double ageRand = 1.0 + static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX) / (2.0 - 1.0));

    int speedInt = std::round(speedRand);
    int positionInt = std::round(positionRand);
    int sizeInt = std::round(sizeRand);
    int nameInt = std::round(nameRand);
    int ageInt = std::round(ageRand);

    rat newrat;
    
    switch (speedInt) {
        case 1:
            newrat.speed = rat1.speed;
            break;
        case 2:
            newrat.speed = rat2.speed;
            break;
    } switch (positionInt) {
        case 1:
            newrat.position = rat1.position;
            break;
        case 2:
            newrat.position = rat2.position;
            break;
    } switch (sizeInt) {
        case 1:
            newrat.size = rat1.size;
            break;
        case 2:
            newrat.size = rat2.size;
            break;
    } switch (nameInt) {
        case 1:
            newrat.name = rat1.name;
            break;
        case 2:
            newrat.name = rat2.name;
            break;
    } switch (ageInt) {
        case 1:
            newrat.age = rat1.age;
            break;
        case 2:
            newrat.age = rat2.age;
            break;
    }

    return newrat;
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