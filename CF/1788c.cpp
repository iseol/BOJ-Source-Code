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

        if (n % 2 == 0) {
            cout << "No\n";
            continue;
        }
        
        cout << "YES\n";
        for (int i = 1; i <= (n-1)/2; i++) cout << i << ' ' << (2*n)-((n-1)/2)+i << '\n';
        for (int i = (n+1)/2; i <= n; i++) cout << i << ' ' << i+((n+1)/2) << '\n';
        
    }
}