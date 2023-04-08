#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (char c : s) {
        if (c >= 'A' && c <= 'Z') cout << (char)(c+32);
        else cout << (char)(c-32);
    }
}