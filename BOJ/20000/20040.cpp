#include <iostream>
using namespace std;

int p[500000];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return 0;

    p[b] = a;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    fill(p, p+n, -1);

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (!merge(a, b)) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}