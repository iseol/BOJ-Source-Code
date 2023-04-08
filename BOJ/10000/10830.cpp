#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix;
typedef long long ll;

matrix operator * (matrix &a, matrix &b) {
    int n = a.size();
    matrix c(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= 1000;
        }
    }

    return c;
}

int main() {
    int n;
    ll b;
    cin >> n >> b;

    matrix a(n, vector<int>(n));
    matrix ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
        ans[i][i] = 1;
    }

    while (b > 0) {
        if (b & 1) {
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}