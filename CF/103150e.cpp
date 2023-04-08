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

        string s, t;
        cin >> s >> t;

        bool flag = false;
        for (char c : t) {
            if (c == 'o') {
                flag = true;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
}