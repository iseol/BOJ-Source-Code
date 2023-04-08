#include <iostream>
#include <algorithm>
using namespace std;

int a[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int st = 0;
    int en = n-1;

    int ans1 = 1e9+5;
    int ans2 = 1e9+5;
    while (st < en) {
        if (abs(ans1 + ans2) > abs(a[st] + a[en])) {
            ans1 = a[st];
            ans2 = a[en];
        }
        if (abs(a[st] + a[en-1]) <= abs(a[st+1] + a[en])) en--;
        else st++;
    }
    cout << ans1 << ' ' << ans2;
}   