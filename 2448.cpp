#include <iostream>
using namespace std;

int n;
char board[3080][6150];
string triangle[3] = {"  *  ",
                      " * * ",
                      "*****"};

void sol(int t, int x, int y) {
    if (t == 1) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) board[x+i][y+j] = triangle[i][j];
        }
        return;
    }

    sol(t/2, x, y+3*t/2);
    sol(t/2, x+3*t/2, y);
    sol(t/2, x+3*t/2, y+3*t);
}

int main() {
    for (int i = 0; i < 3080; i++) {
        fill(board[i], board[i]+6150, ' ');
    }
     ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    sol(n/3, 0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n*2-1; j++) cout << board[i][j];
        cout << '\n';
    }
}