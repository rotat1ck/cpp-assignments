#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<string> readFile(ifstream &file) {
    char buff[1024];
    vector<string> result;
    while(file.getline(buff, 1024)) {
        result.push_back(string(buff));
    }
    return result;
}

int main() {
    string s1;

    // создание объекта файла
    ifstream fromFile;

    // открытие файла для чтения
    fromFile.open("C:\\vscode\\cpp-assignments\\classwork\\2024.12\\in.txt");
    
    // получение первой строки (не использовать)
    // fromFile >> s1;
    // cout << s1;

    // открытие файла для записи
    ofstream toFile("C:\\vscode\\cpp-assignments\\classwork\\2024.12\\out.txt", ofstream::app);
    
    // запись в файл
    toFile << "мяу";

    char ch1[128];
    char ch2[128];

    // // методы для чтения строк 
    // fromFile.getline(ch1, 1024);
    // fromFile.get(ch2, 128);

    // // перевод char в string
    // string res1(ch1);
    // string res2(ch2);

    // // вывод данных
    // cout << res1 << endl;
    // cout << res2 << endl;

    // метод получения содержимого файла
    vector<string> fileContain = readFile(fromFile);

    // чтения полученного массива
    for (auto line : fileContain) {
        cout << line << endl;
    }

    // закрытие файлов
    fromFile.close();
    toFile.close();
}