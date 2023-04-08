#include <iostream>
#include <numeric>
using namespace std;

int a[1005], r[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) {
        cout << 0 << '\n' << a[0];
        return 0;
    }

    int k = 0;
    for (int i = 0; i < n-1; i++) {
        if (gcd(a[i], a[i+1]) != 1) {
            k++;
            r[i] = 1;
        }
    }

    cout << k << '\n';
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
        if (r[i] != 0) cout << r[i] << ' ';
    }
}