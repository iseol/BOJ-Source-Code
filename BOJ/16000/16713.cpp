#include <iostream>
using namespace std;

int v[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        v[i] = v[i-1] ^ a;
    }

    int temp = 0;
    for (int i = 0; i < q; i++) {
        int s, e;
        cin >> s >> e;
        temp ^= v[s-1];
        temp ^= v[e];
    }

    cout << temp;
}