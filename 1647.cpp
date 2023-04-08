#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<tuple<int, int, int>> edge;
int p[100001];

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
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({c, a, b});
    }

    sort(edge.begin(), edge.end());
    int e = edge.size();

    int cnt = 0, res = 0;
    for (int i = 0; i < e; i++) {
        int cost, a, b;
        tie(cost, a, b) = edge[i];

        if (!merge(a, b)) continue;

        res += cost;
        cnt++;
        if (cnt == n-2) break;
    }
    cout << res;
}