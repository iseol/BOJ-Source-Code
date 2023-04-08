#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int ans = 0;
        int n;
        cin >> n;
        while (n--) {
            int cx, cy, r;
            cin >> cx >> cy >> r;

            double dist1 = sqrt((cx-x1)*(cx-x1) + (cy-y1)*(cy-y1));
            double dist2 = sqrt((cx-x2)*(cx-x2) + (cy-y2)*(cy-y2));

            double eps = .000001;

            if ((dist1-r < eps && dist2-r < eps) || (dist1 > r && dist2 > r)) continue;
            else ans++;
        }
        cout << ans << '\n';
    }
}