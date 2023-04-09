#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int l, r, a;
        cin >> l >> r >> a;

        int k = r - (r % a) - 1;
        
        int ans = r/a + r%a;
        if(k >= l) ans = max(ans, k/a + k%a);

        cout << ans << '\n';
    }
}