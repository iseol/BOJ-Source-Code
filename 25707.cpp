#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        ans += abs(arr[i]-arr[i+1]);
    }
    ans += abs(arr[0]-arr[n-1]);

    cout << ans;
}