#include <iostream>
#include <algorithm>
using namespace std;

int a[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);

    if (n % 2 == 0) cout << a[n/2 - 1];
    else cout << a[n/2];
}