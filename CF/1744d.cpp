#include <iostream>
using namespace std;

bool vis[200005];

int exponent(int x) {
    int ans = 0;
    while (x > 1) {
        x >>= 1;
        ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        fill(vis+1, vis+n+1, false);

        int twos = 0;

        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            while (temp % 2 == 0) {
                temp /= 2;
                twos++;
            }
        }

        int k;
        if (n == 1) {
            if (twos >= n) {
                cout << 0 << '\n';
                continue;
            }
        }

        for (int i = 1; i <= 30; i++) {
            if (n < (1<<i)) {
                k = (1<<i) / 2;
                break;
            }
        }

        int oper = 0;
        if (twos >= n) {
            cout << 0 << '\n';
            continue;
        }


        [&] () {
        for (; k > 0; k >>= 1) {
            for (int i = k; i <= n; i+=k) {
                if (vis[i]) continue;

                twos += exponent(k);
                oper++;
                vis[i] = true;

                if (twos >= n) {
                    cout << oper << '\n';
                    return;
                }
            }
        }
        cout << -1 << '\n';
        

        } ();
    }
}