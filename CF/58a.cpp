#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    char last = '!';
    for (char c : s) {
        if (c == 'h' && last == '!') last = c;
        else if (c == 'e' && last == 'h') last = c;
        else if (c == 'l' && last == 'e') last = '@';
        else if (c == 'l' && last == '@') last = c;
        else if (c == 'o' && last == 'l') last = c;
    }
    cout << (last == 'o' ? "YES" : "NO");
}