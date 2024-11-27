#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int first(const vector<int> &nums, int &n) {
    return count_if(nums.begin(), nums.end(), [=](int a) -> bool { return a % 2 == 0; });
}

void second(const vector<int> &nums, int &n) {
    vector<double> res;
    for (int i = 0; i <= n; ++i) {
        double sum = accumulate(nums.begin() + i, nums.begin() + (n + i), sum);
        res.push_back(sum);
    }
    
    for (auto num: res) {
        cout << num << " ";
    }
}

// void three(const vector<int> &nums) {
//     vector<double> res;

//     for_each(nums.begin(), nums.end(), [](int i){res[i]});

//     for (auto num: res) {
//         cout << num << " ";
//     }
// }


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
    int n = 2;
    cout << "1: " << first(nums, n) << endl;
    cout << "2: ";
    second(nums, n);
    vector<int> nums1{0, 4, 43, 67, 192};
    // cout << "3: ";
    // three(nums1);
    cout << "\n5: " << five(nums1);
    int num = 100;
    cout << "\n6: ";
    cout << six(nums1, num);
    return 0;
}