#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

long long a[205];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n+m; i++) cin >> a[i];
        sort(a, a+n+m-1);
        reverse(a, a+n+m);

        cout << accumulate(a, a+n, 0LL) << '\n';       
    }
}