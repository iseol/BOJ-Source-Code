#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b == c || a + c == b || b + c == a) cout << "YES" << '\n';
        else cout << "NO\n";
    }
}