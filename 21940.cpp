#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d[201][201];
constexpr int INF = 987654321;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fill(d[i], d[i]+n+1, INF);
    for (int i = 1; i <= n; i++) d[i][i] = 0;

    while (m--) {
        int a, b, t;
        cin >> a >> b >> t;
        d[a][b] = min(d[a][b], t);
    }
    
    int c;
    cin >> c;
    vector<int> fr;

    for (int i = 1; i <= c; i++) {
        int temp;
        cin >> temp;
        fr.push_back(temp);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k]+d[k][j]) d[i][j] = d[i][k]+d[k][j];
            }
        }
    }

    int mn = INF;
    for (int x = 1; x <= n; x++) {
        [&] () {
            int dist = -1;
            for (int f : fr) {
                if (d[f][x] == INF || d[x][f] == INF) return;
                dist = max(dist, d[f][x]+d[x][f]);
            }
            
            mn = min(mn, dist);
        } ();
    }

    vector<int> res;
    for (int x = 1; x <= n; x++) {
        [&] () {
            int dist = -1;
            for (int f : fr) {
                if (d[f][x] == INF || d[x][f] == INF) return;
                dist = max(dist, d[f][x]+d[x][f]);
            }
            if (dist == mn) {
                res.push_back(x);
            }
        } ();
    }
    
    sort(res.begin(), res.end());
    for (int x : res) cout << x << ' ';
}