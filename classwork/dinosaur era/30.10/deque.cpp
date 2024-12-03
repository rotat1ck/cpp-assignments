#include <iostream>
#include <deque>

using namespace std;

int main() 
{
    deque<int> d;

    d.push_back(1);
    d.push_front(2);
    d.push_back(3);

    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_back();
    d.pop_front();

    cout << d.front() << endl;
    cout << d.back() << endl;

    cout << boolalpha << d.empty();

    return 0;
}