#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int freq[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        vector<vector<int>> v(n, vector<int>(n-1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-1; j++) cin >> v[i][j];
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            fill(freq, freq+n+1, 0);
            for (int j = 0; j < n; j++) {
                if (v[j].empty()) continue;
                freq[v[j].back()]++;
            }

            int most;
            for (int j = 1; j <= n; j++) {
                if (freq[j] > 1) most = j;
            }

            for (int j = 0; j < n; j++) {
                if (v[j].back() == most) v[j].pop_back();
            }

            ans.push_back(most);
        }

        reverse(ans.begin(), ans.end());
        for (auto i : ans) cout << i << ' ';
        cout << '\n';
        
    }
}