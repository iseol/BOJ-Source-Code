#include <iostream>
#include <algorithm>
using namespace std;

int a[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);

        if (a[0] == a[n-1]) cout << n << '\n';
        else cout << "1\n";
    }
}