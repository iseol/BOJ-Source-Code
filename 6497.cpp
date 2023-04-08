#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

tuple<int, int, int> edge[200000];
int p[200000];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    p[b] = a;
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (1) {
        int m, n;
        cin >> m >> n;
        if (m == 0 && n == 0) return 0;

        int w = 0;
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            w += z;

            edge[i] = {z, x, y};
        }

        //
        sort(edge, edge+n);
        fill(p, p+n, -1);
        
        int cnt = 0;
        int cost = 0;
        for (int i = 0; i < n; i++) {
            int x, y, z;
            tie(z, x, y) = edge[i];
            
            if (!merge(x, y)) continue;
            cnt++;
            cost += z;
            if (cnt == n-1) break;
        }
        
        cout << w - cost << '\n';
    }
}