#include <iostream>
#include <vector>

using namespace std;

struct person {
    string name;
    int age;
    double height;
};

ostream &operator<<(ostream &os, person &pers) {
    os << pers.name << " " << pers.age << " " << pers.height << endl;
    return os;
}

template <typename t>
ostream &operator<<(ostream &os, vector<t> &vec) {
    os << "Вектор: \n";
    for (int i = 0; i < vec.size(); ++i) {
        os << i + 1 << ". \t" << vec[i] << endl;
    }
    return os;
}

template <typename t>
void look(vector<t> vec) {
    cout << vec;
}

int main() {
    vector<person> persList;
    person one = {"Олег", 32, 180};
    persList.push_back(one);
    cout << persList;

    // 🥨
}
