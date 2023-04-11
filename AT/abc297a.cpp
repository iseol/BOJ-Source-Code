#include <iostream>
using namespace std;

int t[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> t[i];

    int ans = -1;
    for (int i = 0; i < n-1; i++) {
        if (t[i+1] - t[i] <= d) {
            ans = t[i+1];
            break;
        }
    }

    cout << ans;
}