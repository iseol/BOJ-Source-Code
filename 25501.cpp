#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    
    while (tc--) {
        string s;
        cin >> s;
        
        int ans  = 0;
        int l = 0;
        int r = (int)(s.length()) - 1;
        while (1) {
            ans++;
            if (l >= r) {
                cout << 1 << ' ';
                break;
            }
            else if (s[l] != s[r]) {
                cout << 0 << ' ';
                break;
            }
            else {
                l++;
                r--;
            }
        }
        
        //int n = (int)(s.length()-1);
        cout << ans << '\n';
    }
}