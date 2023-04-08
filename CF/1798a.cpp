#include <iostream>
using namespace std;

int a[105], b[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int mxa = -1;
        int mxb = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) swap(a[i], b[i]);

            mxa = max(mxa, a[i]);
            mxb = max(mxb, b[i]);
        }
        
        cout << ((mxa == a[n-1]) && (mxb == b[n-1]) ? "YES\n" : "NO\n");
    }
}