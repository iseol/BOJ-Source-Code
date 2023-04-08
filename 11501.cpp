#include <iostream>
#include <vector>
using namespace std;

int arr[1'000'001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) cin >> arr[i];

        int mx = arr[n-1];
        long long ans = 0;
        for (int i = n-2; i >= 0; i--) {
            if (arr[i] > mx) mx = arr[i];
            ans += (mx - arr[i]);
        }
        cout << ans << '\n';
    }
}