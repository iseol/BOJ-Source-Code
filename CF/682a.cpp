#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    long long ans = 0;
    for (int x = 1; x <= n; x++) {
        ans += (m+(x%5))/5;
    }

    cout << ans;
}