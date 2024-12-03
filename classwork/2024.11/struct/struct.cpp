#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct account {
    string fullName;
    int accNumber;
    double balance;
    string phoneNumber;
};

void addBalance(account &acc, double money) {
    acc.balance += money;
}

void withdrawBalance(account &acc, double money) {
    if (acc.balance >= money) {
        acc.balance -= money;
    }
}

account createAccount(string fullName, int accNumber, double balance, string phoneNumber) {
    return account{fullName, accNumber, balance, phoneNumber};
};

account findAccount(vector<account> accs, string name) {
    auto it = find_if(accs.begin(), accs.end(), [=](account a){return a.fullName == name;});

    return it != accs.end() ? *it : account{"", -1, -1, ""};
}
int main() {
    account acc1 = {
        .fullName = "Rodion Burdakov",
        .accNumber = 411311,
        .balance = 1500.02
    };

    // добавление баланса к переменной типа acoount
    addBalance(acc1, 1000);

    // вывод баланса с переменной типа acoount
    withdrawBalance(acc1, 500);

    cout << acc1.fullName << " " << acc1.balance << endl;

    // создание переменной с типом account 
    account acc2 = createAccount("Oleg Olegovich", 1234231, 12.2, "+79871234344");

    // вектор аккаунтов
    vector<account> acclist;

    // способы добавления аккаунтов в вектор
    acclist.push_back(acc1);
    acclist.push_back(createAccount("Oleg Olegovich", 1234231, 12.2, "+79871234344"));

    // поиск аккаунтов в векторе по имени пользователя
    account f = findAccount(acclist, "Oleg Olegovich");
    cout << f.fullName << " " << f.balance;
    
}