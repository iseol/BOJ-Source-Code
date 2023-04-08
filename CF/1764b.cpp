#include <iostream>
#include <numeric>
using namespace std;

int a[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> a[i];
        
        int g = a[0];
        for (int i = 1; i <= n; i++) {
            g = gcd(g, a[i]);
        }

        cout << a[n] / g << '\n';
    }
}