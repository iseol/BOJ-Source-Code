#include <iostream>
#include <vector>
using namespace std;

int a[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i-1] == 1 && a[i] == 0 && a[i+1] == 1) {
            k++;
            a[i+1] = 0;
        }
    }

    cout << k;
}