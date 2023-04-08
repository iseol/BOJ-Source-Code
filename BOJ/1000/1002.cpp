#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double d = sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
        double e = .000001;

        if (d == 0) { // 동심원
            if (r1 == r2) cout << -1 << '\n'; // 일치
            else cout << 0 << '\n';
        }
        else if (abs(r1-r2) > d) cout << 0 << '\n'; // 안에서 만나지 않을 때
        else if (r1+r2 < d) cout << 0 << '\n'; //  밖에서 만나지 않을 때
        else if (abs(r1+r2 - d) < e) cout << 1 << '\n'; // 외접할 때
        else if (abs(abs(r1-r2) - d) < e) cout << 1 << '\n'; // 내접할 때
        else cout << 2 << '\n'; // 두 점에서 만날 때
    }
}