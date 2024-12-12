#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> encodeMsg(string msg, string key) {
    vector<int> encodedMsg;
    for (int i = 0; i < msg.length(); ++i) {
        char ch = msg[i];
        char k = key[i % key.length()];
        encodedMsg.push_back((int)((byte)ch ^ (byte)k));
    }
    return encodedMsg;
}

string decodeMsg(vector<int> msg, string key) {
    string decodedMsg;
    for (int i = 0; i < msg.size(); ++i) {
        char ch = msg[i];
        char k = key[i % key.length()];
        decodedMsg.push_back((char)((byte)ch ^ (byte)k));
    }
    return decodedMsg;
}

int main() {
    string key = "wowowo";
    string msg = "hello world";
    vector<int> eMsg = {31, 10, 27, 3, 24, 79, 0, 0, 5, 3, 19};
    cout << decodeMsg(eMsg, key);
}