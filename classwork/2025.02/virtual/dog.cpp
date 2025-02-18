#include <iostream>

using namespace std;

class Animal {
protected:
    string name;
public:
    Animal() {
        cout << "Animal constructor\n";
    }
    virtual void Foo() {
        cout << "Animal\n";
    }

    virtual ~Animal() {
        cout << "Animal destructor\n";
    }
};

class Dog : public Animal {
public:
    void Foo() override {
        cout << "Dog\n";
    }
};

class Cat : public Animal {
public:
    Cat() {
        cout << "Cat constructor\n";
    }
    void Foo() override {
        cout << "Cat\n";
    }

    ~Cat() {
        cout << "Cat destructor\n";
    }
};

int main() {
    // Animal an;
    // Dog d;
    // d.Foo();

    Animal* cat = new Cat();
    cat->Foo();
    delete cat;
}