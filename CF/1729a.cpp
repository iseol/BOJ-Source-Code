#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int a, b, c;
        cin >> a >> b >> c;

        int f = a-1;
        int s = abs(b-c)+abs(c-1);
        if (f == s) cout << 3 << '\n';
        else if (f < s) cout << 1 << '\n';
        else if (f > s) cout << 2 << '\n';
    }
}