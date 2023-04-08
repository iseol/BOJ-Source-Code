#include <iostream>
#define h first 
#define w second
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;

        pair<int, int> arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i].h >> arr[i].w;
        }

        pair<int, int> arrq1[q], arrq2[q];
        for (int i = 0; i < q; i++) cin >> arrq1[i].h >> arrq1[i].w >> arrq2[i].h >> arrq2[i].w;
        for (int i = 0; i < q; i++) {
            long long ans = 0;
            for (int j = 0; j < n; j++) {
                if (arrq1[i].h < arr[j].h && arr[j].h < arrq2[i].h) {
                    if (arrq1[i].w < arr[j].w && arr[j].w < arrq2[i].w) ans += arr[j].h * arr[j].w;
                }
            }
            cout << ans << '\n';
        }
    }
}