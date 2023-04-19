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

        string s;
        cin >> s;
        
        map<char, int> freqa, freqb;
        for (auto& c : s) freqb[c]++; 
        
        int ans = -1;
        for (int i = 0; i < n-1; i++) {
            freqa[s[i]]++;

            if (freqb[s[i]] == 1) freqb.erase(s[i]);
            else freqb[s[i]]--;

            ans = max(ans, (int)(freqa.size()) + (int)(freqb.size()));
        }

        cout << ans << '\n';
    }
}