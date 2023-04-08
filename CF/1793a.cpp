#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        long long a, b, n, m;
        cin >> a >> b >> n >> m;

        if (b*(m+1) < m*a) {
            cout << b * n << '\n';
        }
        else {
            long long s = (m+1) / m;
            cout << (a*m*(n / (m+1))) + (min(a, b)*(n%(m+1))) << '\n';
        }

    }
}