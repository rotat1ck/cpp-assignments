#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

int main() {
    // stack<int, deque<int>> s;

    // s.top();

    // queue<int> q;

    set<int> s;

    s.insert(5);
    s.insert(1);
    s.insert(5);

    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }

}