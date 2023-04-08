#include <iostream>
using namespace std;

bool d[2001][2001];
int a[2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) d[i][i] = 1;
    for (int i = 1; i <= n-1; i++) {
        if (a[i] == a[i+1]) d[i][i+1] = 1;
    }
    for (int i = 2; i < n; i++) {
        for (int j = 1; i+j <= n; j++) {
            if (a[j] == a[i+j] && d[j+1][i+j-1]) d[j][i+j] = 1;
        }
    }

    int m;
    cin >> m;

    int s, e;
    while (m--) {
        cin >> s >> e;
        cout << d[s][e] << '\n';
    }
}