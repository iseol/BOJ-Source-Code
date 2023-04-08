#include <iostream>
using namespace std;

int a[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        [] () {
            int n;
            cin >> n;

            for (int i = 0; i < n; i++) cin >> a[i];

            int l = -1, r = -1;
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                sum += a[i];
                
                if (a[i] != 0) {
                    if (l == -1) l = i;
                    else r = i;
                }
            }

            if (sum == 0) {
                cout << "0\n";
                return;
            }

            
            for (int i = l; i <= r; i++) {
                if (a[i] == 0) {
                    cout << "2\n";
                    return;
                }
            }

            cout << "1\n";
        } ();
    }
}