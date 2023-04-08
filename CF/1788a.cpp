#include <iostream>
using namespace std;

int a[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        int twos = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 2) twos++;
        }

        if (twos % 2 != 0) {
            cout << -1 << '\n';
            continue;
        }

        int k;
        if (twos == 0) {
            cout << "1\n";
            continue;
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 2) cnt++;
            if (cnt >= twos/2) {
                k = i;
                break;
            }
        }

        cout << k << '\n';
    }
}