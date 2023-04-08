#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, h, x, y, p;
    cin >> w >> h >> x >> y >> p;

    int cx1 = x;
    int cy1 = y + h/2;

    int cx2 = x + w;
    int cy2 = y + h/2;

    double eps = .000001;
    int ans = 0;

    while (p--) {
        int px, py;
        cin >> px >> py;
        
        double dist1 = sqrt((cx1-px)*(cx1-px) + (cy1-py)*(cy1-py));
        double dist2 = sqrt((cx2-px)*(cx2-px) + (cy2-py)*(cy2-py));
        if ((px >= x && px <= x+w && py >= y && py <= y+h) || (dist1-(h/2) <= eps) || (dist2-(h/2) <= eps)) ans++;
    }
    cout << ans;
}