#include <iostream>
using namespace std;

int p[1000001];

int find(int n) {
    if (p[n] < 0) return n;

    p[n] = find(p[n]);
    return p[n];
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;
    p[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    fill(p, p+n+1, -1);
    while (m--) {
        int q, a, b;
        cin >> q >> a >> b;
        if (!q) merge(a, b);
        else {
            if (find(a) == find(b)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
}