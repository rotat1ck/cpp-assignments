#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <variant>

using namespace std;

// глобальные переменные (хранят последние результаты шифрования)
vector<int> lastEncrypted;
string lastMsg;
string lastKey;

// определение основных функций-меню
void startMenu();
void decodeMenu();
void encodeMenu();

// переопределение оператора для чтения вектора
ostream& operator<<(ostream& os, const vector<int> &vec) {
    for (int num : vec) {
        os << num << " ";
    }
    return os;
}

// костыль, мне хотелось чтоб одна функция выдавала разные типы данных
// лучше бы просто сделал две разные функции
using ResultType = variant<string, vector<int>>;
ResultType readClipboardText(const bool isVector) {
    string temp = "";
    if (OpenClipboard(NULL)) {
        if (IsClipboardFormatAvailable(CF_TEXT)) {
            HGLOBAL hGlob = GetClipboardData(CF_TEXT);
            if (hGlob) {
                char* pch = static_cast<char*>(GlobalLock(hGlob));
                if (pch) {
                    temp = pch;
                    GlobalUnlock(hGlob);
                }
            }
        }
        CloseClipboard();
    }

    if (isVector) {
        vector<int> clipboardText;
        istringstream iss(temp);
        int number;
        while (iss >> number) {
            clipboardText.push_back(number); 
        }
        return clipboardText;
    } else {
        return temp;
    }
}

// функция которая помещает текст в буфер обмена
bool setClipboardText(const string &text) {
    if (OpenClipboard(NULL)) {
        EmptyClipboard();

        HGLOBAL hGlob = GlobalAlloc(GMEM_MOVEABLE, text.size() + 1);
        if (hGlob) {
            memcpy(GlobalLock(hGlob), text.c_str(), text.size() + 1);
            GlobalUnlock(hGlob);

            SetClipboardData(CF_TEXT, hGlob);
        }

        CloseClipboard();
        return true;
    } else {
        return false;
    }
}

// функция которая считывает только числа и добавляет их в вектор (для дешифрации)
vector<int> getUserInput() {
    cout << "Введите числа зашифрованного сообщения через пробел и нажмите ENTER: ";
    bool noEnter = true;
    int converted = 0;
    vector<int> toDecode;
    while (noEnter) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == '\r') {
                noEnter = false;
                break;
            } else if (ch >= '0' && ch <= '9') {
                converted = converted * 10 + (ch - '0');
                cout << ch;
            } else if (ch == 32) {
                toDecode.push_back(converted);
                cout << " ";
                converted = 0;
            }
            
        }
    }

    if (converted != 0 || !toDecode.empty()) {
        toDecode.push_back(converted);
    }

    return toDecode;
}

// функция шифрования
vector<int> encodeMsg(string &msg, string &key) {
    vector<int> encodedMsg;
    for (int i = 0; i < msg.length(); ++i) {
        char ch = msg[i];
        char k = key[i % key.length()];
        encodedMsg.push_back((int)((std::byte)ch ^ (std::byte)k));
    }
    return encodedMsg;
}

// функция дешифрования
string decodeMsg(vector<int> &msg, string &key) {
    string decodedMsg;
    for (int i = 0; i < msg.size(); ++i) {
        char ch = msg[i];
        char k = key[i % key.length()];
        decodedMsg.push_back((char)((std::byte)ch ^ (std::byte)k));
    }
    return decodedMsg;
}

// функция 1-го раздела дешифрации (ручной ввод сообщения и ключа)
void decodeManual() {
    vector<int> toDecode = getUserInput();

    string key;
    cout << "\nВведите ключ: ";
    getline(cin, key);

    string decodedMsg = decodeMsg(toDecode, key);
    cout << "Расшифрованное сообщение: " << decodedMsg << endl;

    if (setClipboardText(decodedMsg)) {
        cout << "Расшифрованное сообщение скопировано в буфер обмена.\n" << endl;
    } else {
        cout << "Не удалось добавить сообщение в буфер обмена.\n" << endl;
    }
}

// функция 1-го раздела шифрации (ручной ввод сообщения и ключа)
void encodeManual() {
    cout << "Введите сообщение: ";
    string msg;
    getline(cin, msg);
    lastMsg = msg;

    cout << "Введите ключ: ";
    string key;
    getline(cin, key);
    lastKey = key;

    vector<int> encodedMsg = encodeMsg(msg, key);
    lastEncrypted = encodedMsg;
    string toClipboard = "";
    cout << "Зашифрованное сообщение: ";
    for (int i = 0; i < encodedMsg.size(); ++i) {
        cout << encodedMsg[i] << " ";
        toClipboard += to_string(encodedMsg[i]) + " ";
    }
    cout << endl;

    if (setClipboardText(toClipboard)) {
        cout << "Зашифрованное сообщение скопировано в буфер обмена.\n" << endl;
    } else {
        cout << "Не удалось добавить зашифрованное сообщение в буфер обмена.\n" << endl;
    }
}

// функция 2-го раздела дешифрации (считывание сообщения из буфера обмена и ввод ключа)
void decodeFromClipboard() {
    vector<int> numbers = get<vector<int>>(readClipboardText(true));
    if (!numbers.empty()) {
        cout << "Сообщение в буфере обмена: " << numbers << endl;
        string key;
        cout << "Введите ключ: ";
        getline(cin, key);

        string decodedMsg = decodeMsg(numbers, key);
        cout << "Расшифрованное сообщение: " << decodedMsg << "\n";

        if (setClipboardText(decodedMsg)) {
            cout << "Расшифрованное сообщение скопировано в буфер обмена.\n" << endl;
        } else {
            cout << "Не удалось добавить сообщение в буфер обмена.\n" << endl;
        }
    } else {
        cout << "Нет текста в буфере обмена.\n" << endl;
    }

    
}

// функция 2-го раздела шифрации (считывание сообщения из буфера обмена и ввод ключа)
void encodeFromClipboard() {
    string msg = get<string>(readClipboardText(false));
    if (msg.empty()) {
        cout << "Нет текста в буфере обмена.\n" << endl;
        return;
    } 

    cout << "Сообщение в буфере обмена: " << msg << endl;
    lastMsg = msg;

    string key;
    cout << "Введите ключ: ";
    getline(cin, key);
    lastKey = key;
        
    vector<int> encodedMsg = encodeMsg(msg, key);
    lastEncrypted = encodedMsg;
        
    string toClipboard = "";
    cout << "Зашифрованное сообщение: ";
    for (int i = 0; i < encodedMsg.size(); ++i) {
        cout << encodedMsg[i] << " ";
        toClipboard += to_string(encodedMsg[i]) + " ";
    }
    cout << endl;

    lastEncrypted = encodedMsg;

    if (setClipboardText(toClipboard)) {
        cout << "Зашифрованное сообщение скопировано в буфер обмена.\n" << endl;
    } else {
        cout << "Не удалось добавить сообщение в буфер обмена.\n" << endl;
    }
}

// под-меню 3-го раздела дешифрации (дешифрация сообщения по ключам из файла)
void decodeFileMenu() {
    cout << "ESC - Вернуться назад\nВыберите функцию: \n" << "1. Ручной ввод сообщения\n2. Копирование сообщения из буфера обмена" << endl;
    vector<char> allowedKeys= {'1', '2'};
    vector<int> msg;
    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 27) {
                system("cls");
                decodeMenu();
                return;
            } else if (find(allowedKeys.begin(), allowedKeys.end(), ch) != allowedKeys.end()) {
                switch (ch) {
                    case '1': {
                        system("cls");
                        msg = getUserInput();
                        break;
                    } case '2': {
                        system("cls");
                        msg = get<vector<int>>(readClipboardText(true));
                        break;
                    }
                }
                break;
            }
            system("cls");
            cout << "Некорректный ввод\n";
            decodeFileMenu();
        }
    }
    string filename;
    cout << "Введите название файла с ключами: ";
    getline(cin, filename);

    ifstream fromfile;
    fromfile.open(filename);

    ofstream toFile("decoded.txt", ofstream::app);
    if (fromfile.is_open()) {
        char buff[1024];
        vector<string> result;
        while(fromfile.getline(buff, 1024)) {
            result.push_back(string(buff));
        }
        toFile << "----------DECRYPTION BEGIN----------\n";
        for (auto line : result) {
            toFile << line << " - " << decodeMsg(msg, line) << endl;
        }
        toFile << "-----------DECRYPTION END-----------\n" << endl;
    }

    cout << "Результат сохранен в decoded.txt\n\n";
}

// под-меню 3-го раздела шифрации (шифрование сообщений из файла по ключю) 
void encodeFileMenu() {
    cout << "Введите название файла с сообщениями: ";
    string filename;
    getline(cin, filename);

    cout << "Введите ключ: ";
    string key;
    getline(cin, key);

    ifstream fromfile;
    fromfile.open(filename);

    ofstream toFile((key + ".txt"), ofstream::app);
    if (fromfile.is_open()) {
        char buff[1024];
        vector<string> result;
        while(fromfile.getline(buff, 1024)) {
            result.push_back(string(buff));
        }
        toFile << "----------ENCRYPTION BEGIN----------\n";
        for (auto line : result) {
            toFile << line << " - " << encodeMsg(line, key) << endl;
        }
        toFile << "-----------ENCRYPTION END-----------\n" << endl;
    }

    cout << "Результат сохранен в " << key << ".txt\n\n";
}

// основное меню дешифрации (под-меню основного меню)
void decodeMenu() {
    cout << "ESC - Вернуться назад\nВыберите функицю: \n" << "1. Ручной ввод\n2. Расшифровка сообщения из буфера обмена\n3. Расшифровка сообщения по ключам из файла\n4. Последнее зашифрованное сообщение" << endl;
    vector<char> allowedKeys= {'1', '2', '3', '4'};
    char ch;
    while(true) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 27) {
                system("cls");
                startMenu();
                return;
            } else if (find(allowedKeys.begin(), allowedKeys.end(), ch) != allowedKeys.end()) {
                switch(ch) {
                    case '1': {
                        system("cls");
                        decodeManual();
                        break;
                    } case '2': {
                        system("cls");
                        decodeFromClipboard();
                        break;
                    } case '3': {
                        system("cls");
                        decodeFileMenu();
                        break;
                    } case '4': {
                        system("cls");
                        if (lastEncrypted.empty()) {
                            cout << "Нет последнего зашифрованного сообщения\n\n";
                            break;
                        }
                        string key;
                        cout << "Введите ключ: ";
                        getline(cin, key);
                        cout << "Расшифрованное сообщение: " << decodeMsg(lastEncrypted, key) << "\n\n";
                        break;
                    }
                }
                decodeMenu();
            }
            system("cls");
            cout << "Некорректный ввод\n";
            decodeMenu();
        }
    }
}

// основное меню шифрации (под-меню основного меню)
void encodeMenu() {
    cout << "ESC - Вернуться назад\nВыберите функцию: \n" << "1. Ручной ввод\n2. Шифрование сообщения из буфера обмена\n3. Шифрование сообщений из файла" << endl;
    vector<char> allowedKeys= {'1', '2', '3'};
    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 27) {
                system("cls");
                startMenu();
                return;
            } else if (find(allowedKeys.begin(), allowedKeys.end(), ch) != allowedKeys.end()) {
                switch (ch) {
                    case '1': {
                        system("cls");
                        encodeManual();
                        break;
                    } case '2': {
                        system("cls");
                        encodeFromClipboard();
                        break;
                    } case '3': {
                        system("cls");
                        encodeFileMenu();
                        break;
                    }
                }
                encodeMenu();
            }
            system("cls");
            cout << "Некорректный ввод\n";
            encodeMenu();
        }
    }
}

// основное меню
void startMenu() {
    cout << "ESC - Закрыть программу" << endl;
    vector<char> allowedKeys= {'1', '2', '3'};
    cout << "Выберете функцию: \n" << "1. Зашифровать сообщение\n2. Расшифровать сообщение\n3. Последнее защифрованное сообщение" << endl;
    char ch;
    while(true) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 27) {
                exit(0);
            } else if (find(allowedKeys.begin(), allowedKeys.end(), ch) != allowedKeys.end()) {
                switch(ch) {
                    case '1': {
                        system("cls");
                        encodeMenu();
                        break;
                    } case '2': {
                        system("cls");
                        decodeMenu();
                        break;
                    } case '3': {
                        system("cls");
                        if (lastMsg.empty() || lastKey.empty() || lastEncrypted.empty()) {
                            cout << "Нет зашифрованного сообщения.\n" << endl;
                        } else {
                            cout << "Последнее сообщение: " << lastMsg << endl;
                            cout << "Последний ключ: " << lastKey << endl;
                            cout << "Последнее зашифрованное сообщение: " << lastEncrypted << "\n\n";
                        }
                        break;
                    }
                }
                startMenu();
            }
            system("cls");
            cout << "Некорректный ввод\n";
            startMenu();
        }
    }
}

// utf-8 и запуск основного меню
int main() {
    system("chcp 65001");
    system("cls");
    startMenu();

    // 🥨
}