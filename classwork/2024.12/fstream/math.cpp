#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> createVector(ifstream &file) {
    int buff;
    vector<int> result;
    while (file >> buff) {
        result.push_back(buff);
    }
    return result;
}

double getAverage(vector<int> &nums) {
    double sum = accumulate(nums.begin(), nums.end(), 0.0);
    double avg = sum / nums.size();
    return avg;
}

double getVariance(vector<int> nums) {
    double avg = getAverage(nums);
    for (int i = 0; i < nums.size(); ++i) {
        nums[i] = pow(nums[i] - avg, 2);
    }
    double sum = accumulate(nums.begin(), nums.end(), 0.0);
    double variance = sum / nums.size();
    return variance;
}

double standartDeviation(vector<int> &nums) {
    double variance = getVariance(nums);
    return sqrt(variance);
}

double getRange(vector<int> &nums) {
    int max = *max_element(nums.begin(), nums.end());
    int min = *min_element(nums.begin(), nums.end());

    return static_cast<double>(max) - static_cast<double>(min);
}

int main() {
    ifstream petrov("C:\\vscode\\cpp-assignments\\classwork\\2024.12\\fstream\\txt's\\petrov.txt");
    ifstream ivanov("C:\\vscode\\cpp-assignments\\classwork\\2024.12\\fstream\\txt's\\ivanov.txt");

    vector<int> petrovNums = createVector(petrov);
    vector<int> ivanovNums = createVector(ivanov);

    cout << "\nПетров: \n";
    cout << "Среднее ариф:\t" << getAverage(petrovNums) << endl;
    cout << "Дисперсия:\t" << getVariance(petrovNums) << endl;
    cout << "Сред. квадр:\t" << standartDeviation(petrovNums) << endl;
    cout << "Размах:\t" << getRange(petrovNums) << endl;

    cout << "\nИванов: \n";
    cout << "Среднее ариф:\t" << getAverage(ivanovNums) << endl;
    cout << "Дисперсия:\t" << getVariance(ivanovNums) << endl;
    cout << "Сред. квадр:\t" << standartDeviation(ivanovNums) << endl;
    cout << "Размах:\t" << getRange(ivanovNums) << endl;

    // 🥨
}