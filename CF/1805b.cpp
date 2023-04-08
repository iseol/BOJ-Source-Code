#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int idx = 0;
        char t = s[0];
        for (int i = 0; char c : s) {
            if (c <= t) {
                t = c;
                idx = i;
            }
            i++;
        }

        cout << s[idx];
        for (int i = 0; i < n; i++) {
            if (i != idx) cout << s[i];
        }
        cout << '\n';
    }
}