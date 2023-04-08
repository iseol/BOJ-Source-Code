#include <iostream>
using namespace std;

int a[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        
        for (int i = 0; i < n; i++) cin >> a[i];

        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans += ((a[i] - 1) / (2*a[0] - 1));
        }

        cout << ans << '\n';
    }
}