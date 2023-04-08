#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int ans = 0;
    while (n--) {
        int cnt = 0;
        for (int i = 0; i < 3; i++) {

            int x;
            cin >> x;
            if (x == 1) cnt++;

        }
        if (cnt >= 2) ans++;
    }

    cout << ans;
}