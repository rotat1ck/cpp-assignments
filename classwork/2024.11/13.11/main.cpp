#include <iostream>
#include <vector>
#include <memory>

using namespace std;

double avg(const vector<double>& qs) {
    double acc = 0;
    for (double i : qs) {
        acc += i;
    }
    return acc / qs.size();
}

void avg(const vector<double>& qs, double &a) {
    double acc = 0;
    for (double i : qs) {
        acc += i;
    }
    a = acc / qs.size();
    cout << a << endl;
}

int main() {
    vector<double> rds{345, 34.23, 1.0/2.0, 441};  
    vector<int> ris{345, 34, 1, 441}; 
    double a;
    avg(rds, a);
    cout << avg(rds) << endl;
}