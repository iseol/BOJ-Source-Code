#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        int n, k;
        cin >> n >> k;

        vector<int> cnt(51);

        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;

            if (l > k || r < k) continue;
            else {
                for (int j = l; j <= r; j++) cnt[j]++;
            }
        }

        int mx = -1;
        for (int i = 1; i <= 50; i++) mx = max(mx, cnt[i]);
        
        vector<int> maxes;
        for (int i = 1; i <= 50; i++) {
            if (cnt[i] == mx) maxes.push_back(i);
        }

        if (maxes.size() == 1 && maxes[0] == k) cout << "YES\n";
        else cout << "NO\n"; 
    }
}