#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int first(const vector<int> &nums, int &n) {
    return count_if(nums.begin(), nums.end(), [=](int a) -> bool { return a % 2 == 0; });
}

void second(const vector<int> &nums, int n) {
    vector<double> res;
    for (int i = 0; i <= n; ++i) {
        double sum = accumulate(nums.begin() + i, nums.begin() + (n + i + 1), 0.0);
        res.push_back(sum / n);
    }

    for (auto num : res) {
        cout << num << " ";
    }
}

void three(vector<int>& vec) {
    double avg = accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
    for (auto num : vec) {
        cout << num - avg << " ";
    }
}

int four(vector<int> vec) {
    vector<int> predResult;
    copy_if(vec.begin(), vec.end(), back_inserter(predResult), [](int x){return x % 13 == 0 && x != 0;});
    if (predResult.size() > 0) {
        return *max_element(predResult.begin(), predResult.end());
    } else {
        return -1;
    }
}

double five(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    if (size % 2 != 0) {
        return nums[size / 2];
    } else {
        return nums[size / 2 - 1] + nums[size / 2];
    }
}

int six(const vector<int> &nums, int &n) {
    return count_if(nums.begin(), nums.end(), [=](int a) -> bool { return a > n; }); 
}

int main() {
    vector<int> nums{1, 2, 3, 4, 6};
    vector<int> nums1{0, 13, 26, 14, 6};

    // 1
    int n = 2;
    cout << "1: " << first(nums, n);

    // 2
    cout << "\n2: ";
    second(nums, n);

    // 3
    cout << "\n3: ";
    three(nums1);

    // 4
    cout << "\n4: " << four(nums1);;

    // 5
    cout << "\n5: " << five(nums1);

    // 6
    int num = 10;
    cout << "\n6: ";
    cout << six(nums1, num);
    return 0;
}