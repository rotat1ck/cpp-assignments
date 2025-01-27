#include <iostream>

using namespace std;

class Foo {
    mutable int k;
    string n;

public:
    Foo(){
        cout << "foooo" << endl;
    }

    explicit Foo(int _k, string _n) {
        k = _k;
        n = _n;
    }

    const int GetK() const {
        return k;
    }

    void SetK(int _k) {
        k = _k;
    }

    Foo operator +(Foo &_foo) {
        this->k += _foo.k;
        return *this;
    }

    friend ostream& operator<<(ostream &os, const Foo &foo) {
        return os << foo.k << " " << foo.n << " ";
    }

};

template <typename T>
class ZOV {
    T text;
    T goidatext;
public:
    ZOV() {}

    ZOV(T _text) {
        text = _text;
    }

    void setText(T _text) {
        text = _text;
    }

    void setGoidaText(T _text) {
        goidatext = _text;
    }

    T getText() {
        return text;
    }

    T getGoidaText() {
        return goidatext;
    }

    ZOV operator+(ZOV &_zov) {
        this->text += _zov.text;
        return *this;
    }

    friend ostream &operator<<(ostream& os, ZOV &_zov) {
        return os << _zov.text << " " << _zov.goidatext;
    }
};


int main() {
    ZOV<string> a("zov");
    ZOV<string> b;
    b.setText("goida");

    a + b;
    a.setGoidaText("goidatext");
    cout << a;
}