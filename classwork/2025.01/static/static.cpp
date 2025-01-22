#include <iostream>
#include <rotatick/timer.hpp>

using namespace std;

class DB {
protected:
    static string db_name;
    static string ip;
    static int port;
    static string username;
    static string pass;
public:
    static void connect(string _username, string _pass) {
        if (_username == username && _pass == pass) {
            cout << "Подключание успешно xD" << endl;
            cout << "DB Name: " << db_name << endl;
            cout << "IP: " << ip << endl;
            cout << "Port: " << port << endl;
        } else {
            cout << "Не удалось подключаиться" << endl;
        }
    }
};

class users : DB {
private:
    static int userCount;
public:
    static int getUserCount() {
        return userCount;
    }
    static void changeUserCount(int n) {
        userCount = n;
    }
    static string getDbName() {
        return db_name;
    }
};

string DB::db_name = "prod";
string DB::ip = "77.77.77.77";
int DB::port = 7777;
string DB::username = "admin";
string DB::pass = "pass";
int users::userCount = 0;

int main() {
    Timer::startTimer();

    DB::connect("admin", "pass");

    cout << users::getUserCount() << endl;
    users::changeUserCount(15);
    cout << users::getUserCount() << endl;
    cout << users::getDbName();

    Timer::stopTimer();
}