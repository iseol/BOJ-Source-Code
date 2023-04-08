#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int ans = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        t += arr[i];
        ans += t;
    }
    cout << ans;
}
