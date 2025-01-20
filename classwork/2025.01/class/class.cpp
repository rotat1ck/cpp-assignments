#include <iostream>
#include <string>
#include <vector>
#include <ostream>

using namespace std;

class student {
private:
    string name;
    int age;
    string group;
public:
    student(string _name, int _age, string _group) {
        name = _name;
        age = _age;
        group = _group;
    }
};

class todo {
private:
    vector<string> list;
    string lastTask;
public:
    todo() {}

    void addTask(string &task) {
        list.push_back(task);
        lastTask = task;
    }

    string getLastTask() {
        return lastTask;
    }

    vector<string> getTasks() {
        return list;
    }
};

ostream &operator<<(ostream &os, vector<string> &vec) {
    os << "[" << endl;
    for (int i = 0; i < vec.size(); i++) {
        os << i + 1 << ". " << vec[i] << " " << endl;
    }
    os << "]";
    return os;
}

int main() {
    student abc("John", 18, "A");
    string input;

    todo todoList;
    for (int i = 0; i < 5; ++i) {
        getline(cin, input);
        todoList.addTask(input);
    }
    vector<string> vec = todoList.getTasks();
    cout << vec;

    // 🥨
}