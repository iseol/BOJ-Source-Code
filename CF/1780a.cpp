#include <iostream>
#include <vector>
using namespace std;

int a[305];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        vector<int> even;
        vector<int> odd;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) {
                even.push_back(i);
            }
            else odd.push_back(i);
        }

        if (odd.size() >= 3) {
            cout << "YES\n";

            cout << odd[0] << ' ' << odd[1] << ' ' << odd[2] << '\n';
        } 
        else if (even.size() >= 2 && odd.size() >= 1) {
            cout << "YES\n";

            cout << even[0] << ' ' << even[1] << ' ' << odd[0] << '\n';
        }
        else cout << "NO\n";
    }
}