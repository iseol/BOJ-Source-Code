#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

multiset<int> c;
pair<int, int> jem[300005]; // value, mass

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> jem[i].second >> jem[i].first;
    sort(jem, jem+n);
    int c_i;
    for (int i = 0; i < k; i++) {
        cin >> c_i;
        c.insert(c_i);
    }

    long long val = 0;
    for (int i = n-1; i >= 0; i--) {
        if (!c.empty()) {
            auto it = c.lower_bound(jem[i].second);
            if (it == c.end()) continue;
            c.erase(it);
            val += jem[i].first;
        }
    } // 가장 가치가 높은 보석을 담을 수 있는 가방 중 가장 무게가 가벼운 가방을 찾다
    cout << val;
}