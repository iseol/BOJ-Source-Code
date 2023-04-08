#include <iostream>
using namespace std;

int cnt[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;

        string books;
        cin >> books;

        for (auto c : books) cnt[c-'a']++;

        string ans = "";
        for (int i = 0; i < k; i++) {
            char c = 'a';
            for (int j = 0; j < n/k; j++) {
                if (cnt[c-'a']) {
                    cnt[c-'a']--;
                    c++;
                }
                else break;
            }
            ans += c;
        }
        
        cout << ans << '\n';
        fill(cnt, cnt+26, 0);
    }
}