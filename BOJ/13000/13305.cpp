#include <iostream>
using namespace std;

typedef long long ll;

ll cost[100001], dist[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n-1; i++) cin >> dist[i];
    for (int i = 1; i <= n; i++) cin >> cost[i];

    ll cst = 1e9 + 1;
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        if (cst > cost[i]) cst = cost[i];
        res += cst * dist[i];
    }
    cout << res;
}