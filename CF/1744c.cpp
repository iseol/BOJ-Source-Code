#include <iostream>
#include <vector>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        char c;
        cin >> n >> c;

        string s;
        cin >> s;
        s += s;
        
        int ans = 0;
        vector<int> idx;
        for (int i = 0; i < 2*n; i++) {
            if (s[i] == c) idx.push_back(i);
            else if (s[i] == 'g') {
                while (!idx.empty()) {
                    int cur = idx.back();
                    idx.pop_back();
                    ans = max(ans, i-cur);
                }
            }
        }

        cout << ans << '\n';
    }
}