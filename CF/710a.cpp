#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    if (s == "a8" || s == "a1" || s == "h8" || s == "h1") cout << 3;
    else if (s[0] == 'a' || s[0] == 'h' || s[1] == '1' || s[1] == '8') cout << 5;
    else cout << 8; 
}