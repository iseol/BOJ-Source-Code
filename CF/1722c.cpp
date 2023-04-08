#include <iostream>
#include <vector>
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

        map<string, int> m;

        vector<string> v[3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                string s;
                cin >> s;
                v[i].push_back(s);
                if (m[s] == 0) m[s] = 1;
                else if (m[s] == 1) m[s] = 2;
                else if (m[s] == 2) m[s] = 3;
            }
        }
        for (int i = 0; i < 3; i++) {
            int ans = 0;
            for (string s : v[i]) {
                if (m[s] == 2) ans += 1;
                else if (m[s] == 1) ans += 3;
            }
            cout << ans << ' ';
        }
        cout << '\n';
        
    }
}