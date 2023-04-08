#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

#define X first
#define Y second
using namespace std;

vector<tuple<double, int, int>> edge;
pair<double, double> node[101];
int p[101];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return true;
    p[b] = a;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    fill(p, p+n+1, -1);
    for (int i = 1; i <= n; i++) {
        cin >> node[i].X >> node[i].Y;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;

            edge.push_back({sqrt((node[i].X-node[j].X)*(node[i].X-node[j].X)+(node[i].Y-node[j].Y)*(node[i].Y-node[j].Y)), i, j});
        }
    }

    sort(edge.begin(), edge.end());
    int e = edge.size();


    double ans = 0;
    int cnt = 0;
    for (int i = 0; i < e; i++) {
        int a, b;
        double cost;
        tie(cost, a, b) = edge[i];
        if (merge(a, b)) continue;
        ans += cost;
        cnt++;
        if (cnt == n-1) break;
    }

    cout << fixed;
    cout.precision(2);
    cout << ans;
}