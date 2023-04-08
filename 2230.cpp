#include <iostream>
#include <algorithm>
using namespace std;

int a[100005];
int mn = 0x7fffffff;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a+n);

    int en = 0;
    for (int st = 0; st < n; st++) {
        while (en < n && a[en] - a[st] < m) en++;
        if (en == n) break;
        mn = min(mn, a[en] - a[st]);
    }
    cout << mn;
}
