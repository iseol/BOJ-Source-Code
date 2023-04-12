#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;

        int l = s.length();

        if (s[0] != s[l-1]) {
            for (int i = 0; i < l-1; i++) cout << s[i];
            cout << s[0] << '\n';
        }
        else cout << s << '\n';
    }
}