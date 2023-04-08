#include <iostream>
using namespace std;

int a[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;

        int odds = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            if (a[i] % 2 == 1) odds++;
        }


        while (q--) {
            int type, x;

            cin >> type >> x;
            if (type == 1) {
                if (x % 2 == 1) {
                    sum += odds * x;
                    odds = 0;
                }
                else if (x % 2 == 0) {
                    sum += odds * x;
                }
            }
            else if (type == 0) {
                if (x % 2 == 1) {
                    sum += (n-odds) * x;
                    odds = n;
                }
                else if (x % 2 == 0) {
                    sum += (n-odds) * x;
                }
            }

            cout << sum << '\n';
        }

    }
}