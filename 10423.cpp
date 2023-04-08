#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int p[1001];
vector<tuple<int, int, int>> edge;

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

    int n, m, k;
    cin >> n >> m >> k;
    fill(p, p+n+1, -1);

    int plz, pl;
    cin >> pl;
    k--;
    while (k--) {
        cin >> plz;
        merge(plz, pl);
    }

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({w, u, v});
    }

    sort(edge.begin(), edge.end());
    int e = edge.size();
    int ans = 0, cnt = 0;
    for (int i = 0; i < e; i++) {
        int cost, a, b;
        tie(cost, a, b) = edge[i];

        if (!merge(a, b)) continue;
        ans += cost;
        cnt++;
        if (cnt == n-1) break;
    }
    cout << ans;
}