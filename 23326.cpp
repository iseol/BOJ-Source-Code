#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<int> board;

    int n, q;
    cin >> n >> q;

    bool temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        if (temp) board.insert(i);
    }

    int query;
    int cur = 1;
    while (q--) {
        
        cin >> query;
        switch (query) {
            case 1: {
                int i;
                cin >> i;
                if (board.find(i) == board.end()) board.insert(i);
                else board.erase(i);
                break;
            }
            case 2: {
                int x;
                cin >> x;
                cur = (cur+x) % n;
                if (cur == 0) cur = n;
                break;
            }
            case 3: {
                if (board.empty()) {
                    cout << -1 << '\n';
                    break;
                }
                else if ((board.lower_bound(cur)) != board.end()) {
                    cout << *(board.lower_bound(cur)) - cur << '\n';
                }
                else {
                    int dist = n-cur;
                    dist += *(board.lower_bound(0));
                    cout << dist << '\n';
                }
                break;
            }
        }
    }
}