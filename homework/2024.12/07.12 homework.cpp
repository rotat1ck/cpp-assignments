#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct smartphone {
    string brand;
    string model;
    string os;
    string IMEI;
    string manifactDate;
};

void dropIMEI(smartphone &phone1) {
    phone1.IMEI = "";
}

smartphone createPhone() {
    string brand;
    string model;
    string os;
    string IMEI;
    string manifactDate;

    cout << "Введите брэнд телефона: ";
    getline(cin, brand);
    cout << "Введите модель телефона: ";
    getline(cin, model);
    cout << "Введите операционную систему телефона: ";
    getline(cin, os);
    cout << "Введите индентификатор телефона: ";
    getline(cin, IMEI);
    cout << "Введите дату производства телефона: ";
    getline(cin, manifactDate);

    smartphone phone1 = {
        brand,
        model,
        os,
        IMEI,
        manifactDate
    };

    return phone1;
}

int main() {
    // создание объекта phone1 типа smartphone 
    smartphone phone1 = createPhone();

    // сброс параметра IMEI
    dropIMEI(phone1);
    
    // вывод параметров phone1
    cout << phone1.brand << "\n" << phone1.model << "\n" << phone1.os << "\n" << phone1.IMEI << "\n" << phone1.manifactDate;

    // 🥨
}