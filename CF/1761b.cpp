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
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            
            m[tmp]++;
        }

        int freq = m.size();
        if (freq == 1) cout << "1\n";
        else if (freq == 2) cout << n/2 + 1 << '\n';
        else cout << n << '\n';
    }
}