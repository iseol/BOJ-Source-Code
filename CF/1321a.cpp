#include <iostream>
using namespace std;

int a[105], b[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x = 0;
    int y = 0;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < n; i++) {
        if (a[i] == 1 && b[i] == 0) x++;
        else if (a[i] == 0 && b[i] == 1) y++;
    }

    if (x == 0) cout << -1;
    else {
        int p;
        for (p = 1; p * x <= y; p++);
        cout << p;
    }
}