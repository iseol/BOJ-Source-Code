#include <iostream>
using namespace std;

int dp1[2][3], dp2[2][3], arr[100000][3];

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    dp1[0][0] = dp2[0][0] = arr[0][0];
    dp1[0][1] = dp2[0][1] = arr[0][1];
    dp1[0][2] = dp2[0][2] = arr[0][2];

    for (int i = 1; i < n; i++) {
        dp1[1][0] = max(dp1[0][0], dp1[0][1]) + arr[i][0];
        dp1[1][1] = max(max(dp1[0][0], dp1[0][1]), dp1[0][2]) + arr[i][1];
        dp1[1][2] = max(dp1[0][1], dp1[0][2]) + arr[i][2];

        dp2[1][0] = min(dp2[0][0], dp2[0][1]) + arr[i][0];
        dp2[1][1] = min(min(dp2[0][0], dp2[0][1]), dp2[0][2]) + arr[i][1];
        dp2[1][2] = min(dp2[0][1], dp2[0][2]) + arr[i][2];

        dp1[0][0] = dp1[1][0];
        dp1[0][1] = dp1[1][1];
        dp1[0][2] = dp1[1][2];

        dp2[0][0] = dp2[1][0];
        dp2[0][1] = dp2[1][1];
        dp2[0][2] = dp2[1][2];
    }
    if (n == 1) cout << max(max(dp1[0][0], dp1[0][1]), dp1[0][2]) << ' ' << min(min(dp2[0][0], dp2[0][1]), dp2[0][2]);
    else cout << max(max(dp1[1][0], dp1[1][1]), dp1[1][2]) << ' ' << min(min(dp2[1][0], dp2[1][1]), dp2[1][2]);
}