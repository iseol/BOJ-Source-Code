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

    if (a[n-1] < a[n-2] + a[n-3]) {
        cout << "YES\n";
        cout << a[n-2] << ' ' << a[n-1] << ' ' << a[n-3] << ' ';
        for (int i = n-4; i >= 0; i--) cout << a[i] << ' ';
    }
    else cout << "NO";
}