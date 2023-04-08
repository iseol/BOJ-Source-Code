#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        vector<vector<int>> a(n, vector<int>(n));

        int l = 1, r = n*n, t = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (t) a[i][j] = l++;
                else a[i][j] = r--;
                t ^= 1;
            }
            if (i % 2 != 0) reverse(a[i].begin(), a[i].end());
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cout << a[i][j] << " \n"[j == n-1];

    }
}