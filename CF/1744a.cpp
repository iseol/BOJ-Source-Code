#include <iostream>
using namespace std;

int a[51];
char ac[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        fill(ac, ac+n, '?');

        string s;
        cin >> s;
        [&] () {
            for (int i = 0; i < n; i++) {
                int prev = a[i];
                char prevc = s[i];
                for (int j = 0; j < n; j++) {
                    if (a[j] == prev) {
                        if (ac[j] == prevc || ac[j] == '?') ac[i] = prevc;
                        else {
                            cout << "NO\n";
                            return;
                        }
                    }
                }
            }
            cout << "YES\n";
        } ();
        

    }
}