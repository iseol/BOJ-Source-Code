#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int l = n*(a-b);
        int r = n*(a+b);

        if (r < c-d || l > c+d) cout << "No\n";
        else cout << "Yes\n";
    }
}