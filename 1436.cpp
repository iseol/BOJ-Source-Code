#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 1;; i++) {
        if (cnt == n) {
            cout << i-1;
            return 0;
        }

        int temp = i;

        while (temp > 0) { // here
            if (temp % 1000 == 666) {
                cnt++;
                break;
            }
            else temp /= 10;
        }
    }
}