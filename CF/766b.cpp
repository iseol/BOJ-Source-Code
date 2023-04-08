#include <iostream>
#include <algorithm>
using namespace std;

int a[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);

    for (int i = n-1; i >= 2; i--) {
        if (a[i] < a[i-1] + a[i-2]) {
            cout << "YES";
            return 0;
        }
    } 
    cout << "NO";
}