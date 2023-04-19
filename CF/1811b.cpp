#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;

        cout << abs( 
            min({x1, y1, n+1-x1, n+1-y1}) - 
            min({x2, y2, n+1-x2, n+1-y2})
        ) << '\n';
    }
} 
