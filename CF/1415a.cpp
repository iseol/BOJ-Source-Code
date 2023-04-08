#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n, m, r, c;
        cin >> n >> m >> r >> c;

        cout << max({abs(r-1)+abs(c-1), abs(r-1)+abs(c-m), abs(r-n)+abs(c-1), abs(r-n)+abs(c-m)}) << '\n';
    }
}