#include <iostream>
using namespace std;

int d[1000001], pre[1000001];

int main() {
    int x;
    cin >> x;
    fill(d, d+x+1, 987654321);
    d[1] = 0;
    d[2] = d[3] = 1;
    pre[1] = 0;
    pre[2] = pre[3] = 1;

    for (int i = 4; i <= x; i++) {
        if (i % 3 == 0 && d[i/3]+1 < d[i]) {
            d[i] = d[i/3]+1;
            pre[i] = i/3;
        }
        if (i % 2 == 0 && d[i/2]+1 < d[i]) {
            d[i] = d[i/2]+1;
            pre[i] = i/2;
        }
        if (d[i-1]+1 < d[i]) {
            d[i] = d[i-1]+1;
            pre[i] = i-1;
        }
    }

    cout << d[x] << '\n';

    int cur = x;
    while (1) {
        cout << cur << ' ';
        cur = pre[cur];
        if (cur == 0) break;
    }
}