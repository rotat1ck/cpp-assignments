#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "toHash.hpp"

using namespace std;

toHash hasher;
bool finished = false;
const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int max_length = 20;

int file_count = 0;
int line_count = 0;
ofstream file;

void generateCombinations(string current, int currentTrylength, int depth) {
    if (line_count <= 1000000 ) {
        line_count++;
        if (depth == currentTrylength) {
            string hash = hasher.hash(current);
            file << hash << " " << current << endl;
            return;
        }
        
        if (depth < currentTrylength) {
            for (char c : characters) {
                generateCombinations(current + c, currentTrylength, depth + 1);
                if (finished) return;
            }
        }
    } else {
        file_count++;
        line_count = 0;
        file.close();
        file.open("Z:\\cpp_hashes (11-20)\\hashes" + to_string(file_count) + ".txt", ofstream::app);
        cout << "Начал запись файла: hashes" << file_count << ".txt" << endl;
    }
}

int main() {
    system("chcp 65001");
    system("cls");
    file.open("Z:\\cpp_hashes (11-20)\\hashes" + to_string(file_count) + ".txt", ofstream::app);
    cout << "Начал запись файла: hashes" << file_count << ".txt" << endl;
    for (int currentTrylength = 11; currentTrylength <= max_length; ++currentTrylength) {
        cout << "Текущая длина: " << currentTrylength << endl;
        generateCombinations("", currentTrylength, 0);
    }

    system("pause");
    return 0;
}