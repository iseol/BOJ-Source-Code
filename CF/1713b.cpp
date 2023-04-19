#include <iostream>
using namespace std;

int a[100005];
int n;

bool solve() {
    bool decreasing = false;

    if (n == 1) return true;
    
    for (int i = 1; i < n; i++) {
        if (a[i-1] < a[i] && decreasing) return false;
        if (a[i-1] > a[i]) decreasing = true;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;

        for (int i = 0; i < n; i++) cin >> a[i];

        cout << ((solve()) ? "YES\n" : "NO\n");
    }
}