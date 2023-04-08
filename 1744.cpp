#include <iostream>
#include <algorithm>
using namespace std;

int arr[51];

int main() {
    int n;
    cin >> n;

    int pcnt = 0, ncnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > 0) pcnt++;
        if (arr[i] < 0) ncnt++;
    }
    if (n == 1) {
        cout << arr[0];
        return 0;
    }

    sort(arr, arr+n);

    int ans = 0;
    for (int i = n-1; i >= 0; i-=2) {
        if (i-1 < 0) break;
        if (arr[i-1] <= 0) {
            if (arr[i] <= 0) break;
            
            ans += arr[i];
            break;
        }
        else if (arr[i-1] == 1) {
            if (arr[i] == 1) {
                ans += 2;
                continue;
            }
            ans += (1 + arr[i]);
            continue;
        }

        ans += (arr[i] * arr[i-1]);
    }
    if (pcnt == n && pcnt & 1) ans += arr[0];
    if (ncnt == n && ncnt & 1) ans += arr[n-1];

    for (int i = 0; i < n; i+=2) {
        if (i+1 >= n) break;
        if (arr[i+1] > 0) {
            if (arr[i] >= 0) break;
            
            ans += arr[i];
            break;
        }
        else if (arr[i+1] == 0) break;
        
        // arr[i+1] < 0
        ans += (arr[i] * arr[i+1]);
    }

    cout << ans;
}