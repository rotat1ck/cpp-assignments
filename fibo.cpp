#include <iostream>
#include <iostream>

using namespace std;

int main() 
{
    // проверяет находится ли число в послед. фибоначи и выводит его порядковый номер

    int n, i=1, last=0, now=1, next=0;
    cin >> n;
    
    while (n > now) {
        next = last + now;
        last = now;
        now = next;
        i++;
    }
    if (n == now) {
        cout << i;
    } else {
        cout << -1;
    }

}