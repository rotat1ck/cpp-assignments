#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

// Работать в VSCode не будет из-за цветашек и моего медота считывания нажатий)
// Закомпильте и будет красота

bool drawResult(vector<int> &guess, vector<int> &playerNumber) {
    system("cls");

    string output(  "a┌───┐\033[0m b┌───┐\033[0m c┌───┐\033[0m d┌───┐\033[0m\n"
                    "a│ x │\033[0m b│ x │\033[0m c│ x │\033[0m d│ x │\033[0m\n"
                    "a└───┘\033[0m b└───┘\033[0m c└───┘\033[0m d└───┘\033[0m\n");

    for (auto num : guess) {
        size_t pos = 0;
        char ch = '0' + num;
        while ((pos = output.find('x', pos)) != string::npos) {
            output.replace(pos, 1, string(1, ch));
            break;
        }
    }

    string greenColor = "\033[32m";
    string yellowColor = "\033[33m";
    string redColor = "\033[31m";

    string color;

    for (int i = 0; i < 4; ++i) {

        if (guess[i] == playerNumber[i]) {
            color = greenColor;
        } else {
            for (auto num : playerNumber) {
                if (guess[i] == num) {
                    color = yellowColor;
                    break;
                } else {
                    color = redColor;
                }
            }
        }

        size_t pos = 0;
        char markStart;

        switch(i) {
            case 0:
                markStart = 'a';
                break;
            case 1:
                markStart = 'b';
                break;
            case 2:
                markStart = 'c';
                break;
            case 3:
                markStart = 'd';
                break;
        }

        while ((pos = output.find(markStart, pos)) != string::npos) {
            output.replace(pos, 1, color);
        }
    }

    cout << output;

    if (guess == playerNumber) {
        return true;
    } else {
        return false;
    }
}

void startGame(vector<int> &playerNumber) {
    int triesLeft = 6;

    while (triesLeft != 0) {
        cout << "Введите 4 значное число, осталось " << triesLeft << " попыток: ";

        char ch;
        vector<int> guess;
        bool notEnoughNumbers = true;
        
        while (notEnoughNumbers) {
            if (_kbhit()) {
                ch = _getch();
                if (ch >= '1' && ch <= '6') {
                    guess.push_back(ch - '0');
                    cout << ch;
                    if (guess.size() == 4) {
                        break;
                    }
                }
            }
        }

        bool result = drawResult(guess, playerNumber);

        if (result) {
            cout << "\nПоздравляю! Вы угадали число 😊\n";
            system("pause");
            exit(0);
        } else {
            triesLeft--;

        }
    }

    cout <<"\nВы проиграли( Как у вас это вышло? 😞\n";
    system("pause");
    exit(0);
}

int main() {
    system("chcp 65001");
    system("cls");
    
    vector<int> playerNumber;

    char ch;
    bool notEnoughNumbers = true;

    cout << "Введите 4 значное число, разрешенные числа от 1 до 6: ";
    
    while (notEnoughNumbers) {
        if (_kbhit()) {
            ch = _getch();
            if (ch >= '1' && ch <= '6') {
                playerNumber.push_back(ch - '0');
                cout << '*';
                if (playerNumber.size() == 4) {
                    break;
                }
            }
        }
    }

    system("cls");

    string output(  "┌───┐ ┌───┐ ┌───┐ ┌───┐\n"
                    "│ x │ │ x │ │ x │ │ x │\n"
                    "└───┘ └───┘ └───┘ └───┘\n");

    std::cout << output;
    
    startGame(playerNumber);

    return 0;
}