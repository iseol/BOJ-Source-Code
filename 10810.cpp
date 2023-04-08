#include <iostream>
using namespace std;

int a[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    while (m--) {
        int i, j, k;
        cin >> i >> j >> k;

        for (int x = i; x <= j; x++) a[x] = k;
    }

    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}