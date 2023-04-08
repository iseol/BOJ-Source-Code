#include <iostream>
using namespace std;

bool forbidden[26];

int main() {
    int t;
    cin >> t;

    int ans = t;
    while (t--) {
        string s;
        cin >> s;
        
        char prev = s[0];
        forbidden[prev-'a'] = true;
        for (char c : s) {
            if (c != prev) {
                if (forbidden[c-'a']) {
                    ans--;
                    break;
                }
                else {
                    prev = c;
                    forbidden[c-'a'] = true;
                }
            }
        }
        fill(forbidden, forbidden+26, false);
    }
    cout << ans;
}