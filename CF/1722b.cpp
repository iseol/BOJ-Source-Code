#include <iostream>
using namespace std;

string grid[2];

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        
        bool flag = true;
        cin >> grid[0] >> grid[1];

        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 'G') grid[0][i] = 'B';
        }
        for (int i = 0; i < n; i++) {
            if (grid[1][i] == 'G') grid[1][i] = 'B';
            
            if (grid[0][i] != grid[1][i]) flag = false;
        }

        if (flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}