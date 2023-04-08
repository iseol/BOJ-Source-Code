#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[1000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> seq;
    seq.push_back(-1);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > seq.back()) {
            seq.push_back(a[i]);
            cnt++;
        }
        else {
            auto it = lower_bound(seq.begin(), seq.end(), a[i]);
            *it = a[i];
        }
    }

    cout << cnt;
}