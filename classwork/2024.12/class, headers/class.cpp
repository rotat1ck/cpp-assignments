#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "class.hpp"

#define READ_STUDENT_CLASS(x) cout << x.getName() << " " << x.getAge() << endl;

using namespace std;

student::student(string name, int age) {
    _name = name;
    _age = age;
}

int student::getAge() {return _age;}
void student::setAge(int age) {_age = age;}

string student::getName() {return _name;}
void student::setName(string name) {_name = name;}

void studentPrinter(student &s) {
    cout << s.getName() << " " << s.getAge() << endl;
}

int main() {
    student ivan("Ivan", 12);
    ivan.setName("oleg");
    READ_STUDENT_CLASS(ivan)
    
    // 🥨 
}