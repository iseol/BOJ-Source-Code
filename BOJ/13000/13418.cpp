#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<pair<int, int>> uedge, dedge;
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
    m++;
    while (m--) {
        int a, b;
        bool c;
        cin >> a >> b >> c;
        if (c) dedge.push_back({a, b});
        else uedge.push_back({a, b});
    }

    // 최선의 경로의 피로도 구하기
    fill(p, p+n+1, -1);
    int de = dedge.size();
    int cnt = 0; // 몇 개의 간선을 추가했는지
    for (int i = 0; i < de; i++) {
        int a, b;
        tie(a, b) = dedge[i];

        if (!merge(a, b)) continue;
        cnt++;
        if (cnt == n) break;
    }

    int npk = 0; // 최선의 경로일 때 sqrt(피로도)
    int ue = uedge.size();
    if (cnt < n) {
        for (int i = 0; i < ue; i++) {
            int a, b;
            tie(a, b) = uedge[i];
            if (!merge(a, b)) continue;
            npk++; cnt++;
            if (cnt == n) break;
        }
    }

    // zz
    fill(p, p+n+1, -1);
    int pk = 0; // 최악의 경로일 때 sqrt(피로도)
    cnt = 0; // 몇 개의 간선을 추가했는지
    for (int i = 0; i < ue; i++) {
        int a, b;
        tie(a, b) = uedge[i];
        if (!merge(a, b)) continue;
        pk++; cnt++;
        if (cnt == n) break;
    }

    cout << pk*pk - npk*npk;
}