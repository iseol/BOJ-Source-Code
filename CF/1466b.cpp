#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) cin >> a[i];

        set<int> s;
        for (int i = 0; i < n; i++) {
            if (s.find(a[i]) == s.end()) s.insert(a[i]);
            else s.insert(++a[i]);
        }

        cout << s.size() << '\n';
    }
}