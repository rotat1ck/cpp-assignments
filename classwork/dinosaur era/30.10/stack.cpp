#include <iostream>
#include <stack>

using namespace std;


int main() 
{
    stack<int> numstack;

    numstack.push(3);
    numstack.push(4);

    cout << numstack.top() << endl;
    numstack.pop();

    cout << numstack.top() << endl;
    numstack.pop();

    cout << boolalpha << numstack.empty() << endl;

    return 0;
}