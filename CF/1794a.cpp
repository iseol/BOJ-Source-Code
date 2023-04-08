#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        
        string s1 = "";
        string s2 = "";
        for (int i = 0; i < 2*n-2; i++) {
            string s;
            cin >> s;

            if ((int)s.length() == n-1) {
                if (s1 == "") s1 = s;
                else s2 = s;
            }
        }

        reverse(s1.begin(), s1.end());
        if (s1 == s2) cout << "YES\n";
        else cout << "NO\n";
    }
}