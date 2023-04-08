#include <iostream>
using namespace std;

char board[501][501];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int r, c;
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= c; j++) {
            board[i][j] = s[j-1];
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (board[i][j] == 'S') {
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx <= 0 || nx > r || ny <= 0 || ny > c) continue;
                    if (board[nx][ny] == 'W') {
                        cout << 0;
                        return 0;
                    }
                    if (board[nx][ny] == '.') board[nx][ny] = 'D';
                }
            }
        }
    }

    cout << 1 << '\n';
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}