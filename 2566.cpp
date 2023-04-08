#include <iostream>
using namespace std;

int board[10][10];

int main() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) cin >> board[i][j];
    }

    int mx = -1;
    int x, y;

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (board[i][j] > mx) {
                mx = board[i][j];
                x = i;
                y = j;
            }
        }
    }

    cout << mx << '\n';
    cout << x << ' ' << y;
}