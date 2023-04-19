#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        long long ans = 0;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (x == 0) {
                if (!pq.empty()) {
                    ans += pq.top();
                    pq.pop();
                }
            }
            else pq.push(x);
        }

        cout << ans << '\n';
    }
}