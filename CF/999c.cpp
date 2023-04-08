#include <iostream>
using namespace std;

int cnt[26], a[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    
    for (char c : s) cnt[c-'a']++;

    for (int i = 0; i < 26; i++) {
        a[i] = min(cnt[i], k);
        k -= min(cnt[i], k);
    }

    for (char c : s) {
        if (a[c-'a'] > 0) {
            a[c-'a']--;
        }
        else {
            cout << c;
        }
    }
}