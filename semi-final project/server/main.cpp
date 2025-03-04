#include "header/includes.h"
#include "header/settings.h"

#include "src/endpoints.cpp"

int main() {
    try {
        SSLServer svr(cert, key);
        setEndpoints(svr);
        svr.listen(ipInterface, port);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}