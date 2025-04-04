#include <thread>
#include <iostream>
#include <fstream>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;

ofstream file("file.txt", ios::app);

class Goida {
    public:
        mutex mtx;
        condition_variable cv;
        bool ready = false;
        int data = 0;
    
        void receiver() {
            while (true) {
                unique_lock<mutex> lock(mtx);
                cv.wait(lock, [this]{ return this->ready; });
                
                file << this->data << endl;
                this->ready = false;
            }
        }
    
        void generator() {
            file << "- - Start of file - - " << endl;
            for (int i = 0; i < 61; ++i) {
                this_thread::sleep_for(chrono::seconds(1));
                this->data = i;
                this->ready = true;
                cv.notify_one();
            }
            file << "- - End of file - - " << endl;
        }
    };

int main() {
    Goida pc;
    thread t1(&Goida::receiver, &pc);
    thread t2(&Goida::generator, &pc);
    t1.join();
    t2.join();
    

    // 🥨
}