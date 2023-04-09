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
        
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            
            m[tmp]++;
        }

        int freq = -1;

        auto it = m.begin();
        for (; it != m.end(); it++) {
            freq = max(freq, it->second);
        }

        int ans = n - freq;
        while (freq < n) {
            freq *= 2;
            ans++;
        }

        cout << ans << '\n';
        
    }
}