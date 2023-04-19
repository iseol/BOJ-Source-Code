#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        int ans = 1;
        for (long long i = 2; i*i <= n; i++) {
            if (n % i == 0) {
                ans = n / i;
                break;
            }
        }

        cout << ans << ' ' << n - ans << '\n';
    }
}