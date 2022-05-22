#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    string dt = "qwertasdfgzxcv";

    for (char c: dt) {
        if (s[n-1] == c) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}