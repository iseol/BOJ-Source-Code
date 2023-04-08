#include <iostream>
using namespace std;

int p[201], arr[1001];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
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

    bool l;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
           cin >> l;
           if (l) merge(i, j);
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < m-1; i++) {
        if (find(arr[i]) != find(arr[i+1])) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}