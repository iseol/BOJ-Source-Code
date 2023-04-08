#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    cin >> n >> l;

    int board[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> board[i][j];
    }

    int cnt = n*2;

    for (int i = 0; i < n; i++) {
        int lvl = board[i][0];
        int cur = 0;
        bool flag = true; // valid path
        for (int j = 0; j < n; j++) {
            if (!flag) break;
            if (lvl == board[i][j]) cur++;
            else if (lvl + 1 == board[i][j]) {
                if (cur >= l) {
                    if (l == 1) cur = 1;
                    else cur = 0;
                    lvl++;
                }
                else {
                    cnt--;
                    break;
                }
            }
            else if (lvl - 1 == board[i][j]) {
                if (j+l-1 >= n) {
                    cnt--;
                    break;
                }
                else {
                    int nxt = j+l-1;
                    for (int k = j; k <= nxt; k++) {
                        if (board[i][k] != lvl-1) flag = false;
                    }
                    if (flag) {
                        lvl--;
                        j = nxt;
                        cur = 0;
                    }
                    if (!flag) cnt--;
                }
            }
            else {
                cnt--;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int lvl = board[0][i];
        int cur = 0;
        bool flag = true; // valid path
        for (int j = 0; j < n; j++) {
            if (!flag) break;
            if (lvl == board[j][i]) cur++;
            else if (lvl + 1 == board[j][i]) {
                if (cur >= l) {
                    cur = 0;
                    lvl++;
                }
                else {
                    cnt--;
                    break;
                }
            }
            else if (lvl - 1 == board[j][i]) {
                if (j+l-1 >= n) {
                    cnt--;
                    break;
                }
                else {
                    int nxt = j+l-1;
                    for (int k = j; k <= nxt; k++) {
                        if (board[k][i] != lvl-1) flag = false;
                    }
                    if (flag) {
                        lvl--;
                        j = nxt;
                        cur = 0;
                    }
                    if (!flag) cnt--;
                }
            }
            else {
                cnt--;
                break;
            }
        }
    }

    cout << cnt;
}