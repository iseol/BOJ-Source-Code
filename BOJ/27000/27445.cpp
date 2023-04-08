#include <iostream>
using namespace std;

int v[51], h[51];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n-1; i++) cin >> v[i];
    for (int i = 1; i <= m; i++) cin >> h[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            [&] () {
                for (int k = 1; k <= n-1; k++) {
                    if (abs(i-k) + abs(j-1) != v[k]) return;
                }
                for (int k = 1; k <= m; k++) {
                    if (abs(i-n) + abs(j-k) != h[k]) return;
                }
                cout << i << ' ' << j;
                exit(0);
            } ();

        }
    }
}