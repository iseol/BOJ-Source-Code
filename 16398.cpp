#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<tuple<int, int, int>> edge;

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

    int n;
    cin >> n;
    fill(p, p+n+1, -1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int cost;
            cin >> cost;
            if (i == j) continue;
            edge.push_back({cost, i, j});
        }
    }

    sort(edge.begin(), edge.end());
    int e = edge.size();
    int cnt = 0;
    long long res = 0;
    for (int i = 0; i < e; i++) {
        int cost, a, b;
        tie(cost, a, b) = edge[i];

        if (!merge(a, b)) continue;
        cnt++;
        res += cost;
        if (cnt == n-1) break;
    }

    cout << res;
}