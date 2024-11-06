#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        if (temp % 10 == 4) {
            nums.push_back(temp);
        }
    }

    int min = nums[0];
    int index = -1;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < min) {
            min = nums[i];
            index = i;
        }
    }

    cout << "Минимальное число заканчивающееся на 4: " << min << endl;

    cout << "Индекс числа: " << index << endl;
}

