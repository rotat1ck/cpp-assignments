#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <vector>

using namespace std;
mutex mtx;

void Foo(int a) {
    mtx.lock();
    cout << a << endl;
    mtx.unlock();
}

void Two(vector<int> part, int partNumber, int& total) {
    int sum = 0;
    for (int num : part) {
        sum += num;
    }
    mtx.lock();
    cout << "Sum of part " << partNumber << ": " << sum << endl;
    total += sum;
    mtx.unlock();
}



int main() {
    // thread t(Foo, 5);
    // thread d(Foo, 9);
    // t.join();
    // d.join();

    vector<thread> threads(5);
    for (int i = 0; i < 5; ++i) {
        threads[i] = thread(Foo, i);
        mtx.lock();
        cout << "Thread " << i + 1 << ": " << threads[i].get_id() << endl;
        mtx.unlock();
    }

    for (int i = 0; i < 5; ++i) {
        threads[i].join();
    }


    vector<int> nums = {1, 2, 3, 4, 5, 13, 14, 15, 16, 17, 18, 20};


    int partSize = nums.size() / 3;
    vector<int> part1(nums.begin(), nums.begin() + partSize);
    vector<int> part2(nums.begin() + partSize, nums.begin() + partSize * 2);
    vector<int> part3(nums.begin() + partSize * 2, nums.end());

    int total = 0;
    thread t1(Two, part1, 1, ref(total));
    thread t2(Two, part2, 2, ref(total));
    thread t3(Two, part3, 3, ref(total));

    t1.join();
    t2.join();
    t3.join();
    cout << "Total sum: " << total << endl;
    return 0;
}