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

        int t = 1, ans = 0;
        for (int i = 0; i < n-1; i++) {
            if (t) {
                if (s[i] == '1' && s[i+1] == '0') {
                    ans++;
                    t ^= 1;
                }
            }
            else {
                if (s[i] == '0' && s[i+1] == '1') {
                    ans++;
                    t ^= 1;
                }
            }
        }
        cout << ans << '\n';
    }
}