#include <iostream>
using namespace std;

int a[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++) cin >> a[i];

        int cv = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == cv) cv++;
        }

        int w = cv - 1;
        cout << (n-w+k-1) / k << '\n';
    }
}