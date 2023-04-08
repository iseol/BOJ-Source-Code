#include <iostream>
using namespace std;

long long dl[100005], dr[100005];
int a[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        dr[i] += dr[i-1];
        
        if (a[i-1] > a[i]) dr[i] += a[i-1] - a[i];
    }

    for (int i = n; i >= 1; i--) {
        dl[i] += dl[i+1];

        if (a[i+1] > a[i]) dl[i] += a[i+1] - a[i];
    }

    while (m--) {
        int s, t;
        cin >> s >> t;

        if (s < t) cout << dr[t] - dr[s] << '\n';
        else cout << dl[t] - dl[s] << '\n';
    }
}