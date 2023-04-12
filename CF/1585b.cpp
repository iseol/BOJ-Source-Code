#include <iostream>
using namespace std;

int a[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) cin >> a[i];
        
        int k = 0;
        int last = a[n-1];
        for (int i = n-1; i >= 0; i--) {
            if (last < a[i]) {
                k++;
                last = a[i];
            }
        }

        cout << k << '\n';
    }
}