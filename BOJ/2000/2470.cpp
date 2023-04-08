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
    sort(a, a+n);

    int st = 0, en = n-1;

    int ans = 2'000'000'001;

    int ans1, ans2;
    while (st < en) {
        int sum = a[st] + a[en];
        
        if (ans > abs(sum)) {
            ans = abs(sum);
            ans1 = a[st]; ans2 = a[en];
        }

        if (sum > 0) {
            en--;
        }
        else if (sum < 0) {
            st++;
        }
        else break;
    }

    cout << ans1 << ' ' << ans2;
}