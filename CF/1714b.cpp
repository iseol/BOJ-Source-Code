#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        
        map<int, int> s;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;

            if (s.find(a) != s.end()) ans = max(ans, s[a]);
            s[a] = i;
        }
        cout << ans << '\n';
    }
}