#include <iostream>
using namespace std;

int h[104];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        int one = 0;
        for (int i = 0; i < n; i++) {
            cin >> h[i];
            if (h[i] == 1) one++;
        }

        cout << n - (one - (one%2)) + one / 2 << '\n';
    }
}