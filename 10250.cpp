#include <iostream>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int h, w, n;
        cin >> h >> w >> n;

        if (n % h == 0) {
            if (n / h < 10) cout << h << '0' << n/h << '\n';
            else cout << h << n/h << '\n';
        }
        else {
            if (n / h < 9) cout << n % h << '0' << n/h+1 << '\n';
            else cout << n % h << n/h+1 << '\n';
        }
    }
}