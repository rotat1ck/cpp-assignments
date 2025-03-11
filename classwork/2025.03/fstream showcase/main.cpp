#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<string> getLines(ifstream& file) {
    vector<string> lines;
    char buff[1024];
    while (file.getline(buff, 1024) ) {
        lines.push_back(string(buff));
    }
    return lines;
}

int main() {
    ifstream file("logins.txt");
    vector<string> lines = getLines(file);

    for (auto& line : lines) {
        if (line == "goida") {
            cout << "GOIDA";
        }
    }
}