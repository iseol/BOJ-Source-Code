#include <iostream>
using namespace std;

int cnt1[26], cnt2[26]; // upper, lower

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        
        string s;
        cin >> s;

        for (auto& c : s) {
            if ('A' <= c && c <= 'Z') cnt1[c-'A']++;
            else cnt2[c-'a']++;
        }

        int ans = 0, op = 0;
        for (int i = 0; i < 26; i++) {
            ans += min(cnt1[i], cnt2[i]);
            op += abs(cnt1[i] - cnt2[i]) / 2;
        }

        ans += min(k, op);
        cout << ans << '\n';

        fill(cnt1, cnt1+26, 0);
        fill(cnt2, cnt2+26, 0);
    }
}