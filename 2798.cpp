#include <iostream>
using namespace std;
int cards[100];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> cards[i];

    int res = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i == j || j == k || k == i) continue;
                if (cards[i]+cards[j]+cards[k] <= m) {
                    res = max(res, cards[i]+cards[j]+cards[k]);
                }
            }
        }
    }

    cout << res;
}