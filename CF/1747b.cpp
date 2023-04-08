#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        if (n % 2 == 0) {
            cout << n/2 << '\n';

            for (int i = 1; i <= n/2; i++) {
                cout << 3*i-1 << ' ' << 3*(n-i+1) << '\n';
            }
        }
        else {
            cout << n/2 + 1 << '\n';

            for (int i = 1; i <= n/2; i++) {
                cout << 3*i-1 << ' ' << 3*(n-i+1) << '\n';
            }

            int i = n/2+1;
            cout << 3*i-1 << ' ' << 3*i << '\n';
        }

        
    }
}