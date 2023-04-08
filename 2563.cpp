#include <iostream>
using namespace std;

bool board[105][105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        for (int i = x; i < x+10; i++) 
            for (int j = y; j < y+10; j++)
                board[i][j] = true;
    }

    int cnt = 0;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            if (board[i][j]) cnt++;

    cout << cnt;
}