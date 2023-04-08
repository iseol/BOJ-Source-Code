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
            cout << "YES\n";
            for (int i = 0; i < n/2; i++) cout << "1 -1 ";
            cout << '\n';
        }
        else if (n != 3) {
            cout << "YES\n";
            for (int i = 0; i < n/2; i++) cout << n/2-1 << ' ' << -(n/2) << ' ';
            cout << n/2-1 << '\n';
        }
        else cout << "NO\n";
    }
    
}