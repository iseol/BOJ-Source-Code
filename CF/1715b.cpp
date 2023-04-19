#include <iostream>
using namespace std;

long long a[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        long long n, k, b, s;
        cin >> n >> k >> b >> s;
        
        if (b*k <= s && s <= b*k + n*(k-1)) {
            fill(a, a+n, 0);
            a[0] = b*k;
            
            long long left = s - b*k;
            for (int i = 0; i < n; i++) {
                a[i] += min(left, k-1);
                left -= min(left, k-1);
            }

            for (int i = 0; i < n; i++) cout << a[i] << ' ';
            cout << '\n';
        }
        else cout << "-1\n";
    }
}