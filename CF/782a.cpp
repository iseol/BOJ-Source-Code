#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    

    set<int> s;
    int ans = -1;
    for (int i = 1; i <= 2*n; i++) {
        int x;
        cin >> x;

        if (s.find(x) == s.end()) s.insert(x);
        else s.erase(x);

        ans = max(ans, (int)s.size());
    }
    cout << ans;
}