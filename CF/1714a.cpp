#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, h, m;
        cin >> n >> h >> m;
        vector<int> alram;
        
        int cur = 60 * h + m;
        while (n--) {
            cin >> h >> m;
            alram.push_back(h*60 + m);
        }

        sort(alram.begin(), alram.end());
        
        int res = -1;
        for (int s : alram) {
                if (s >= cur) {
                res = s - cur;
                break;
            }
        }
        if (res == -1) {
            res = alram[0] + 1440;
            res -= cur;
            cout << res/60 << ' ' << res%60 << '\n';
        }
        else {
            cout << res/60 << ' ' << res%60 << '\n';
        }
    }
}