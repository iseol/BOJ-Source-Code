#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        long long x, y;
        cin >> x >> y;

        cout << 2*(x-y) << '\n';

        for (long long i = x; i > y; i--) {
            cout << i << ' ';
        }
        for (long long i = y; i < x; i++) {
            cout << i << ' ';
        }

        cout << '\n';
        
    }
}