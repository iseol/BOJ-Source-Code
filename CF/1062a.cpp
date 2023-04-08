#include <iostream>
using namespace std;

int a[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;

            int ren = 0;
            bool flag = true;

            for (int k = i; k <= j; k++) {
                if (k == j) {
                    if (a[k] == a[k-1] + 1) ren++;
                    else flag = false;
                }
                else {
                    if (a[k] + 1 == a[k+1]) ren++;
                    else flag = false;
                } 
            }

            if (flag) {
                if (a[i] == 1 && a[j] == 1000) ans = max(ans, ren);
                else if (a[i] == 1 || a[j] == 1000) ans = max(ans, ren-1);
                else ans = max(ans, ren-2);
            }
        }
    }

    cout << ans;
}