#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        int n, m;
        cin >> n >> m;
        
        string s, t;
        cin >> s >> t;

        reverse(t.begin(), t.end());
        s += t;

        int cnt = 0;
        for (int i = 1; i < n + m; i++) {
            cnt += (s[i] == s[i-1]);
        }

        cout << (cnt <= 1 ? "YES\n" : "NO\n");
    }
}