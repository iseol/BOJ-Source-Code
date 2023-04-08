#include <iostream>
using namespace std;

struct shark {
    int r, c, s, d;
};

int board[101][101]; // shark size, no shark -> 0
shark sharks[10001];
int R, C;

void move(int z) {
    board[sharks[z].r][sharks[z].c] = 0;

    int tmps;
    switch (sharks[z].d) {
        case 1: {
            tmps = sharks[z].s % (2*(R-1));
            bool rev = false;
            while (tmps--) {
                if (sharks[z].r == 1 || sharks[z].r == R) rev = !rev;
                if (!rev) sharks[z].r--;
                else sharks[z].r++;
            }
            if (rev) sharks[z].d = 2;
            break;
        }
        case 2: {
            tmps = sharks[z].s % (2*(R-1));
            bool rev = false;
            while (tmps--) {
                if (sharks[z].r == 1 || sharks[z].r == R) rev = !rev;
                if (!rev) sharks[z].r++;
                else sharks[z].r--;
            }
            if (rev) sharks[z].d = 1;
            break;
        }
        case 3: {
            tmps = sharks[z].s % (2*(C-1));
            bool rev = false;
            while (tmps--) {
                if (sharks[z].c == 1 || sharks[z].c == C) rev = !rev;
                if (!rev) sharks[z].c++;
                else sharks[z].c--;
            }
            if (rev) sharks[z].d = 4;
            break;
        }
         case 4: {
            tmps = sharks[z].s % (2*(R-1));
            bool rev = false;
            while (tmps--) {
                if (sharks[z].r == 1 || sharks[z].r == R) rev = !rev;
                if (!rev) sharks[z].c--;
                else sharks[z].c++;
            }
            if (rev) sharks[z].d = 3;
            break;
        }
    }
    if (board[sharks[z].r][sharks[z].c] != 0) {
        if (board[sharks[z].r][sharks[z].c] > z) {
            sharks[z] = {9999, 9999, 9999, 9999};
        }
        else {
            sharks[board[sharks[z].r][sharks[z].c]] = {9999, 9999, 9999, 9999};
            board[sharks[z].r][sharks[z].c] = z;
        }
    }
    else board[sharks[z].r][sharks[z].c] = z;
}

int main() {
    int m;
    cin >> R >> C >> m;

    for (int i = 1; i <= m; i++) sharks[i] = {9999, 9999, 9999, 9999};

    int rr, cc, ss, dd, zz;
    int mz = 0;
    for (int i = 0; i < m; i++) {
        cin >> rr >> cc >> ss >> dd >> zz;
        mz = max(zz, mz);
        board[rr][cc] = zz;
        sharks[zz] = {rr, cc, ss, dd};
    }

    int cur = 0;
    int res = 0;
    while (cur < C) {
        cur++;
        for (int depth = 1; depth <= R; depth++) {
            if (board[depth][cur] != 0) {
                res += board[depth][cur];
                sharks[board[depth][cur]] = {9999, 9999, 9999, 9999}; // caught shark
                board[depth][cur] = 0;
                break;
            }
        }
        
        for (int i = 1; i <= mz; i++) {
            if (sharks[i].r == 9999) continue;
            move(i);
        }

        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) cout << board[i][j] << ' ';
            cout << '\n';
        }
        cout << '\n';
    }

    cout << res;
}

