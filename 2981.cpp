#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int arr[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int m = abs(arr[1] - arr[0]);
    for (int i = 1; i < n-1; i++) {
        m = gcd(m, abs(arr[i+1] - arr[i]));
    }

    vector<int> p;
    for (int i = 1; i*i <= m; i++) {
        if (m % i == 0) {
            p.push_back(i);
            if (i*i != m) p.push_back(m/i);
        }
    }

    sort(p.begin(), p.end());
    for (auto x : p) {
        if (x == 1) continue;
        else cout << x << ' ';
    }
}