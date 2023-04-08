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
            cout << "1 3 ";
            for (int i = 0; i < n-2; i++) cout << "2 ";
        }
        else {
            for (int i = 0; i < n; i++) cout << "1 ";
        }

        cout << '\n';
    }
}