#include <iostream>
using namespace std;

int a[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        int o = 0;
        int mo = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) o++;
            else mo++;
        }

        if (o == n) cout << n-4 << '\n';
        else {
            bool flag = false;
            for (int i = 0; i < n-1; i++) {
                if (a[i] == -1 && a[i+1] == -1) {
                    flag = true;
                    break;
                }
            }

            if (flag) cout << o-mo+4 << '\n';
            else cout << o-mo << '\n';
        }
    }
}