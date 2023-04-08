#include <iostream>
using namespace std;

int d[21][21][21];

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);

    if (!d[a][b][c]) { // memozation
        if (a < b && b < c) return d[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c); // memozation
        else return d[a][b][c] =  w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1); // memozation
    }

    return d[a][b][c]; // memozation
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if (a == -1 && b == -1 && c == -1) return 0;
        else cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }
}