#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        map<int, int> m;
        
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            m[x]++;
        }

        int diff = 0;
        for (auto i : m) diff++;

        for (int i = 1; i <= n; i++) cout << max(i, diff) << " \n"[i == n];
    }
}