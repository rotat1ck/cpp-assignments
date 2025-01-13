#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <openssl/evp.h>
#include <vector>
#include <thread>
#include <atomic>

#include "../timer.hpp"

using namespace std;

const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int max_length = 10; // Максимальная длина строки

string sha256(const string& str) {
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len;
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();

    EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr);
    EVP_DigestUpdate(ctx, str.c_str(), str.size());
    EVP_DigestFinal_ex(ctx, hash, &hash_len);
    EVP_MD_CTX_free(ctx);

    string result;
    result.reserve(hash_len * 2); // Reserve space for the hex string
    static const char hex_digits[] = "0123456789abcdef";
    for (unsigned int i = 0; i < hash_len; ++i) {
        result.push_back(hex_digits[(hash[i] >> 4) & 0xF]);
        result.push_back(hex_digits[hash[i] & 0xF]);
    }
    return result;
}

bool found = false; // Флаг для остановки потоков

void generateCombinations(string current, int currentTrylength, int depth, const string& target_hash) {
    if (found) return; // Если хэш найден, выходим

    if (depth == currentTrylength) { // Проверяем, достигли ли мы нужной длины
        string hash = sha256(current);
        if (hash == target_hash) {
            found = true; // Устанавливаем флаг, если хэш найден
            cout << "Найдено совпадение: " << current << " -> " << hash << endl;
            return;
        }
    }

    if (depth < currentTrylength) { // Продолжаем рекурсию, если не достигли нужной длины
        for (char c : characters) {
            generateCombinations(current + c, currentTrylength, depth + 1, target_hash);
            if (found) return; // Проверяем флаг после каждой рекурсивной генерации
        }
    }
}

int main() {
    system("chcp 65001");
    system("cls");

    string input_hash;
    cout << "Введите SHA-256 хэш: ";
    getline(cin, input_hash);

    Timer timer;
    timer.startTimer();

    // Генерация комбинаций от длины 1 до max_length
    for (int currentTrylength = 1; currentTrylength <= max_length; ++currentTrylength) {
        cout << "Текущая длина: " << currentTrylength << endl;
        generateCombinations("", currentTrylength, 0, input_hash);
    }
    if (!found) {
        std::cout << "Совпадений не найдено." << std::endl;
    }

    timer.stopTimer();
    system("pause");
    return 0;
}
