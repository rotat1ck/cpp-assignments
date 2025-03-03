#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

void one() {
    ifstream ifile("input1.txt");
    vector<string> lines;
    for (string line ; getline(ifile, line);) {
        lines.push_back(line);
    }

    sort(lines.begin(), lines.end());

    ofstream ofile("output1.txt");
    for (string line : lines) {
        ofile << line << endl;
    }
}

void two() {
    ifstream ifile("input2.txt");
    vector<string> lines;
    for (string line ; getline(ifile, line);) {
        lines.push_back(line);
    }
    
    int charCount = 0;
    int spaceCount = lines.size() - 1;

    for (string line : lines) {
        charCount += line.length();
        for (char ch : line) {
            if (ch == ' ' || ch == '\n' || ch == '\t') {
                spaceCount++;
            }
        }
    }

    double percent = (double)spaceCount / charCount * 100;
    cout << "Строк: " << lines.size() << "\nСимволов: " << charCount << "\nПробелов: " << percent << "%" << endl;
}

void three() {
    ifstream ifile("input3.txt");
    string line;
    getline(ifile, line);

    map<char, int> dict;

    for (char ch : line) {
        ch = tolower(ch);
        if (dict.find(ch) != dict.end()) {
            dict[ch]++;
        } else {
            dict[ch] = 1;
        }
    }

    for (auto ch : dict) {
        cout << ch.first << ": " << ch.second << endl;
    }
}   

int main() {
    one();
    two();
    three();
    return 0;

    // 🥨
}