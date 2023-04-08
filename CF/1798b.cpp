#include <iostream>
#include <vector>
using namespace std;

int cnt[50005], ans[50005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int m;
        cin >> m;

        for (int i = 1; i <= m; i++) {
            int n;
            cin >> n;
            while (n--) {
                int x;
                cin >> x;

                cnt[x] = i; // cnt[i] = i번째 손님이 온 마지막 날
            }
        }

        // fill(ans+1, ans+m+1, -1);
        
        for (int i = 1; i <= 50000; i++) { // ans[i] = i번째 날까지만 온 손님
            ans[cnt[i]] = i; 
        }

        vector<int> res;

        bool flag = true;
        for (int i = 1; i <= m; i++) {
            if (ans[i] == 0) {
                cout << "-1\n";
                flag = false;
                break;
            }
            else res.push_back(ans[i]);
        }

        if (flag) {
            for (auto i : res) cout << i << ' ';
            cout << '\n';
        }
        

        fill(ans, ans+50005, 0);
        fill(cnt, cnt+50005, 0);
    }
}