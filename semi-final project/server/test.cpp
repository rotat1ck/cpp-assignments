#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <rotatick/httplib.h>
#include <iostream>

using namespace std;
using namespace httplib;

int main() {
    SSLClient cli("jsonplaceholder.typicode.com");
    auto res = cli.Get("/posts/5");
    if (res->status == 200) {
        cout << res->body << endl; 
    } 

    return 0;
}