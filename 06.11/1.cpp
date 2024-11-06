#include <iostream>
#include <cmath>

using namespace std;

double findDisp(int* speedList, double avg, int n) 
{
    double E2 = pow(avg, 2);
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += pow(speedList[i], 2);
    }
    
    double E1 = sum / n;
    return (E1 - E2);
}

int main() 
{
    int n, sum;
    cin >> n;
    int speedList[n];
    bool speedFlag = false;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        speedList[i] = temp;
        sum += temp;
        if (temp > 60) {
            speedFlag = true;
        }
    }
    
    if (speedFlag) {
        cout << "Да" << endl;
    } else {
        cout << "Нет" << endl;
    }

    double avg = sum / static_cast<double>(n);

    double disp = findDisp(speedList, avg, n);

    cout << "Среднее арифметическое: " << avg << endl;

    cout << "Дисперсия равна: " << disp << endl;
    
    cout << "Квадратный корень дисперсии: " << sqrt(disp);

}