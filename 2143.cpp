#include <iostream>
#include <algorithm>
using namespace std;

int a[1001], b[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        a[i] = a[i-1] + temp;
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int temp;
        cin >> temp;
        b[i] = b[i-1] + temp;
    }

    vector<int> sa;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            sa.push_back(a[j]-a[i-1]);
        }
    }
    sort(sa.begin(), sa.end());

    vector<int> sb;
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            sb.push_back(b[j]-b[i-1]);
        }
    }

    long long cnt = 0;
    for (int s : sb) {
        if (binary_search(sa.begin(), sa.end(), t-s)) {
            cnt += upper_bound(sa.begin(), sa.end(), t-s) - lower_bound(sa.begin(), sa.end(), t-s);
        }
    }
    cout << cnt;
}