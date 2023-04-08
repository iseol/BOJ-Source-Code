#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
#define X first
#define Y second
using namespace std;

vector<tuple<double, int, int>> edges;
int p[1001];

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

    int n, m;
    cin >> n >> m;
    fill(p, p+n+1, -1);
    pair<long long, long long> node[1001];
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        node[i] = {x, y};
    }

    double res = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (merge(a, b)) cnt++;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) edges.push_back({sqrt((node[i].X-node[j].X)*(node[i].X-node[j].X) + (node[i].Y-node[j].Y)*(node[i].Y-node[j].Y)), i, j});
        }
    }

    sort(edges.begin(), edges.end());
    int e = edges.size();

    for (int i = 0; i < e; i++) {
        double cost;
        int a, b;
        tie(cost, a, b) = edges[i];

        if (!merge(a, b)) continue;
        res += cost;
        cnt++;

        if (cnt == n-1) break;
    }

    cout << fixed;
    cout.precision(2); // zz
    cout << res;
}