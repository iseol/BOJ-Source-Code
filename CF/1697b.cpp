#include <iostream>
#include <algorithm>
using namespace std;

long long a[200005], d[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1, [] (int a, int b) {return a > b;} );

    for (int i = 1; i <= n; i++) d[i] = d[i-1] + a[i];

    while (q--) {
        int x, y;
        cin >> x >> y;
        
        cout << d[x] - d[x-y] << '\n';
    }
    
}