#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int cnt[200001], a[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a+n);
    queue<int> idx;
    vector<int> values;
    
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        if (cnt[a[i]] == 2) {
            idx.push(i);
            values.push_back(a[i]);
        }
        if (cnt[a[i]] > 2) {
            cout << "NO";
            return 0;
        }
    }

    int l = values.size();

    cout << "YES\n";
    cout << n-l << '\n';
    for (int i = 0; i < n; i++) {
        if (i == idx.front()) idx.pop();
        else cout << a[i] << ' ';
    }
    cout << '\n';
    reverse(values.begin(), values.end());
    cout << l << '\n';
    for (int val : values) cout << val << ' ';
}