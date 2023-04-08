#include <iostream>
using namespace std;

int board[9][9];
int cur[9][9];

bool isvalid(int x, int y) {
    bool arrx[10], arry[10], arrsq[10];
    fill(arrx, arrx+10, false); fill(arry, arry+10, false); fill(arrsq, arrsq+10, false); 
    
    for (int i = 0; i < 9; i++) {
        if (cur[x][i] == 0) continue;
        if (arrx[cur[x][i]]) {
            return false;
        }
        else {
            arrx[cur[x][i]] = true;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (cur[i][y] == 0) continue;
        if (arry[cur[i][y]]) {
            return false;
        }
        else {
            arry[cur[i][y]] = true;
        }
    }

    int sx = (x/3)*3;
    int sy = (y/3)*3;
    for (int i = sx; i < sx+3; i++) {
        for (int j = sy; j < sy+3; j++) {
            if (cur[i][j] == 0) continue;
            if (arrsq[cur[i][j]]) {
                return false;
            }
            else {
                arrsq[cur[i][j]] = true;
            }
        }
    }

    return true;
}

void backtracking(int x, int y) {
    for (int n = 1; n <= 9; n++) {
        cur[x][y] = n;

        if (isvalid(x, y)) {
            int nx = 10, ny;
            [&] () {
                for (int i = x; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        if (cur[i][j] == 0) {
                            nx = i;
                            ny = j;
                            return;
                        }
                    }
                }
            } ();
            if (nx == 10) {
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        cout << cur[i][j] << ' ';
                    }
                    cout << '\n';
                }
                exit(0);
            }
            else backtracking(nx, ny);
        }

        cur[x][y] = 0;
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            cur[i][j] = board[i][j];
        }
    }

    int sx = 10;
    int sy;

    [&] () {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == 0) {
                    sx = i;
                    sy = j;
                    return;
                }
            }
        }
    } ();

    if (sx == 10) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    else backtracking(sx, sy);
}