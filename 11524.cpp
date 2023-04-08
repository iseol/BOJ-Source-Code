#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix operator * (matrix &a, matrix &b) {
    matrix c(2, vector<ll>(2));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= 1000000000;
        }
    }

    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    while (tc--) {
        ll k, n;
        cin >> k >> n;

        matrix a(2, vector<ll>(2));
        matrix ans(2, vector<ll>(2));
        ans[0][0] = 1;
        ans[1][1] = 1;
        
        a = {{1, 1}, {1, 0}};

        while (n > 0) {
            if (n & 1) {
                ans = ans * a;
            }
            a = a * a;
            n >>= 1;
        }
        
        cout << k << ' ' << ans[0][1] << '\n';
    }
}