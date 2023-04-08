#include <iostream>
#include <unordered_map>
using namespace std;

int p[200005];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;
    p[a] += p[b];
    p[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int f;
        cin >> f;
        fill(p, p+(2*(f+1)), -1);

        int cur = 0;
        unordered_map<string, int> u;
        while (f--) {
            string f1, f2;
            cin >> f1 >> f2;
            if (u.find(f1) == u.end()) u.insert({f1, ++cur});
            if (u.find(f2) == u.end()) u.insert({f2, ++cur});

            merge(u[f1], u[f2]);
            cout << -p[find(u[f1])] << '\n';
        }
    }
}