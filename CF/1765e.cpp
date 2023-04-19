#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, a, b;
        cin >> n >> a >> b;
        
        if (a > b) cout << 1 << '\n';
        else cout << (n + a - 1) / a << '\n';
    }
}