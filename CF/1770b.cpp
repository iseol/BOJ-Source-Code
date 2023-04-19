#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;

        int l = 1, r = n;

        int t = 1;
        for (int i = 0; i < n; i++) {
            if (t) {
                cout << r << ' ';
                r--;
            }
            else {
                cout << l << ' ';
                l++;
            }

            t ^= 1;
        }
        cout << '\n';
    }
}