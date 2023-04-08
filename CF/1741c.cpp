#include <iostream>
using namespace std;

int n, res, sum;
int d[2001];

void backtracking(int cur, int thick) { // ended in cur
    if (cur >= n) {
        res = min(res, thick);
        return;
    }

    for (int nxt = cur+1; nxt <= n; nxt++) {
        int temp = d[nxt] - d[cur];
        if (temp != sum) continue;
        else backtracking(nxt, max(thick, nxt-cur));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        res = n;

        for (int i = 1; i <= n; i++) {
            int temp;
            cin >> temp;
            d[i] = d[i-1] + temp;
        }

        for (int i = 1; i <= n; i++) {
            sum = d[i];
            backtracking(i, i);
        }

        cout << res << '\n';
    }
}