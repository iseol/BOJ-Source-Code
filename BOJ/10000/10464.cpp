#include <iostream>
using namespace std;

int sol(int x) {
    int res = 0;
    for (int i = ((x>>2)<<2); i <= x; i++) {
        res ^= i;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int s, f;
        cin >> s >> f;
        cout << (sol(s-1) ^ sol(f)) << '\n';
    }
}