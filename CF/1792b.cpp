#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;
        if (a1 == 0) {
            cout << "1\n";
            continue;
        }

        cout << a1 + 2 * min(a2, a3) + min(a1+1,abs(a2-a3)+a4) << '\n';
    }
}