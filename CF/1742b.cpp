#include <iostream>
#include <algorithm>
using namespace std;

int arr[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        [&] () {
            int n;
            cin >> n;
            for (int i = 0; i < n; i++) cin >> arr[i];
            sort(arr, arr+n);
            for (int i = 0; i < n-1; i++) {
                if (arr[i] == arr[i+1]) {
                    cout << "NO\n";
                    return;
                }
            }
            cout << "YES\n";
        } ();

    }
}