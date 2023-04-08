#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        if (n < 10) cout << n << '\n';
        else if (n < 100) cout << 9 + n/10 << '\n';
        else if (n < 1000) cout << 18 + n/100 << '\n';
        else if (n < 10000) cout << 27 + n/1000 << '\n';
        else if (n < 100000) cout << 36 + n/10000 << '\n';
        else if (n < 1000000) cout << 45 + n/100000 << '\n';
    }
}