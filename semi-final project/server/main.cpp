#include "header/includes.h"
#include "header/settings.h"

#include "src/endpoints.cpp"

// Required:
// cpp-httplib: https://github.com/yhirose/cpp-httplib
// SQliteCpp: https://github.com/SRombauts/SQLiteCpp

// Compilation: 

// Windows, MinGW(GCC):
// g++ main.cpp -o server.exe -lssl -lcrypto -lcrypt32 -lbcrypt -lws2_32 -lSQLiteCpp -lsqlite3

// Linux GCC:
// g++ main.cpp -o server -lssl -lcrypto -lSQLiteCpp -lsqlite3

int main() {
    try {
        SSLServer svr(cert, key);
        setEndpoints(svr);
        svr.listen(ipInterface, port);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}