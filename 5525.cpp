#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string s;    
    cin >> s;
    s += "@@";

    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == 'O') continue;
        else {
            int cnt = 0;
            while (s[i+1] == 'O' && s[i+2] == 'I') {
                cnt++;
                if (cnt == n) {
                    ans++;
                    cnt--;
                }
                i += 2;
            }
        }
    }
    cout << ans;
}