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
        if (n == 3) {
            cout << -1 << '\n';
        }
        else if (n % 2 == 0) {
            for (int i = n; i >= 1; i--) cout << i << ' ';
            cout << '\n';
        }
        else {
            int mid = n/2 + 1;
            for (int i = mid; i <= n; i++) cout << i << ' ';
            for (int i = 1; i < mid; i++) cout << i << ' ';
            cout << '\n';
        }
    }
}