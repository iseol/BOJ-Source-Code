#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int board[41][41];
int res[41][41];

int main() {
    int r, c;
    cin >> r >> c;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cin >> board[i][j];
    }
    int t;
    cin >> t;
    
    for (int i = 0; i < r-2; i++) {
        for (int j = 0; j < c-2; j++) {
            vector<int> v;
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) v.push_back(board[i+k][j+l]);
            }
            sort(v.begin(), v.end());
            res[i][j] = v[4];
            //cout << res[i][j] << ' ';
        }
    }

    /*for (int i = 0; i < r-2; i++) {
        for (int j = 0; j < c-2; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }*/
    int cnt = 0;
    for (int i = 0; i < r-2; i++) {
        for (int j = 0; j < c-2; j++) {
            if (res[i][j] >= t) cnt++;
        }
    }

    cout << cnt;
}