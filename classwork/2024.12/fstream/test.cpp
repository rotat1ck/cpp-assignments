#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<string> getData(ifstream &file) {
    char buff[1024];
    vector<string> result;
    while (file.getline(buff, 1024)) {
        result.push_back(string(buff));
    }
    return result;
}

bool checkData(map<string, string> &creds) {
    string username, password;
    cout << "Введите логин: ";
    cin >> username;
    cout << "Введите пароль: ";
    cin >> password;

    if (creds["username"] == username && creds["password"] == password) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ifstream file;
    file.open("C:\\vscode\\cpp-assignments\\classwork\\2024.12\\fstream\\pass.txt");

    vector<string> data = getData(file);
    map<string, string> creds;

    if (data.size() > 0) {
        creds = {
            {"username", data[0]},
            {"password", data[1]}
        };
    } else {
        string username, password;
        cout << "Данные не найдены.\nВведите новый логин: ";
        cin >> username;
        cout << "Введите новый пароль: ";
        cin >> password;

        ofstream writeData;
        writeData.open("C:\\vscode\\cpp-assignments\\classwork\\2024.12\\fstream\\pass.txt");
        writeData << username << endl << password << endl;

        creds = {
            {"username", username},
            {"password", password}
        };
    }

    while (!checkData(creds)) {
        cout << "Неверный логин или пароль!" << endl;
    }

    cout << "Добро пожаловать!";

    // 🥨
}