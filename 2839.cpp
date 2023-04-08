#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int cnt = 0;
    while (n >= 0) {
        if (n % 5 == 0) {
            cout << n/5 + cnt;
            return 0;
        }

        n -= 3;
        cnt++;
    }

    cout << -1;
}