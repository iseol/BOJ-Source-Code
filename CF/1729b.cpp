#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        
        string s;
        cin >> s;

        string ans = "";
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '0') {
                ans += char('a' + (s[i-2]-'0')*10 + (s[i-1]-'0') - 1);
                // cout << s << '\n';
                i -= 2;
            }
            else {
                ans += char('a' + s[i]-'0' - 1);
            }
        }

        reverse(ans.begin(), ans.end());
        cout << ans << '\n';

    }
}