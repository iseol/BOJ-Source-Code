#include <iostream>
using namespace std;

int a[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] %= 2;
        }

        int x = 0;
        for (int i = 0; i < n-1; i++) {
            if (a[i] != a[i+1]) x++;
        }



        
        cout << n-x-1 << '\n';
    }
}