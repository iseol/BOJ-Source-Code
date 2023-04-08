#include <iostream>
using namespace std;

__int128 d[101][101]; // n, m

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main(void) {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= m; i++) d[0][i] = 0;
    for (int i = 0; i <= n; i++) d[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j] = d[i-1][j-1] + d[i-1][j];
        }
    }
    __int128 res = d[n][m];

    print(res);
}