#include <iostream>
using namespace std;

char grid[50][50];
bool forbidden[50][50];
char shape[4][2][2] = {
    {{'*', '*'},
     {'*', ' '}},

    {{'*', '*'},
     {' ', '*'}},

    {{' ', '*'},
     {'*', '*'}},

    {{' ', '*'},
     {'*', '*'}}
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '*') {
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (grid[nx][ny] != '*') forbidden[nx][ny] = true; 
                    }
                }
            }
        }




        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < m-1; j++) {
                
            }
        }
    }
}