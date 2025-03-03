#include <map>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    // pair<int, int> a;
    // a = make_pair(2, 4);
    // cout << a.first << " " << a.second << endl;

    // map<string, int> m;

    // m["a"] = 1;

    // for (auto it : m) {
    //     cout << it.first << " " << it.second << endl;
    // }

    unordered_map<char, int> um;

    string test = "hello world";

    for (char c : test) {
        um[c]++;
    }

    for (auto it = um.begin(); it != um.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }

    // 🥨
}