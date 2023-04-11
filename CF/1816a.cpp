#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        long long a, b;
        cin >> a >> b;

        if (a == 1 || b == 1) {
            cout << 1 << '\n';
            cout << a << ' ' << b << '\n';
        }
        else {
            cout << 2 <<'\n';
            cout << a-1 << ' ' << 1 << '\n';
            cout << a << ' ' << b << '\n';
        }
    }
}