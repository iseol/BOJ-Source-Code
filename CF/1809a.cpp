#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;

        vector<int> cnt(10);
        for (char c : s) {
            cnt[c-'0']++;
        }
        bool flag1 = false;
        bool flag2 = false;
        for (int i = 0; i <= 9; i++) {
            if (cnt[i] == 3) flag1 = true;
            if (cnt[i] == 4) flag2 = true;
        }

        if (flag1) cout << 6 << '\n';
        else if (flag2) cout << -1 << '\n';
        else cout << 4 << '\n';
    }
}