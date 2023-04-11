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

        if (n % 2 == 0) {
            int apb = n-1;
            cout << apb / 2 << ' ' << apb/2 + 1 << ' ' << 1 << '\n';
        }
        else {
            if (n % 4 == 1) cout << n/2-1 << ' ' << n/2+1 << ' ' << 1 << '\n';
            else if (n % 4 == 3) cout << n/2-2 << ' ' << n/2+2 << ' ' << 1 << '\n';
        }
    }
}