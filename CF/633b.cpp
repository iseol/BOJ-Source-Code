#include <iostream>
using namespace std;

int a[500005];

int main() {
    int m;
    cin >> m;

    for (int i = 1; i <= 500000; i++) {
        for (int j = 5; j <= i; j *= 5) {
            a[i] += i/j;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= 500000; i++) {
        if (a[i] == m) cnt++;
    }
    cout << cnt << '\n';
    for (int i = 1; i <= 500000; i++) {
        if (a[i] == m) cout << i << ' ';
    }
}