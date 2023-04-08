#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 0;
    for (char c : s) {
        ans += (c-'A')/3 + 3;
        if (c == 'S' || c == 'V' || c == 'Y' || c == 'Z') ans--;
    }

    cout << ans;
}