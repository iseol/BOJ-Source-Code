#include <iostream>
using namespace std;

int a[10005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) a[i]++;
        }
        for (int i = 1; i < n; i++) {
            if (a[i] >= a[i-1]) {
                if (a[i] % a[i-1] == 0) a[i]++;
            }
        }

        for (int i = 0; i < n; i++) cout << a[i] << ' ';
        cout << '\n';
    }
}