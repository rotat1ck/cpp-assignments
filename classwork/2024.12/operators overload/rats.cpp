#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Rat {
    string name;
    int age;
};

ostream &operator<<(ostream &os, Rat &rat) {
    os << rat.name << ", age: " << rat.age << " month";
    return os;
}

ostream &operator<<(ostream &os, vector<int> &v) {
    os << "[";
    for (int num : v) {
        os << num << ", ";
    }
    os << "]";
    return os;
}

istream &operator>>(istream &is, Rat &rat) {
    // Rat Name 12
    string type;
    string name;
    int age;
    is >> type >> name >> age;
    rat.name = name;
    rat.age = age;
    return is;
}

int main() {
    ofstream file;
    file.open("C:\\VSCode\\c++ projects\\main cpp\\classwork\\2024.12\\struct\\out.txt");
    cout << "Введите свою структуру: " << endl;
    Rat rat;
    cin >> rat;
    cout << rat;
    file << rat << endl;
    vector<int> nums = {1, 2, 3, 4, 5};
    file << nums << endl;
    file.close();
    return 0;
}