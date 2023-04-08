#include <iostream>
using namespace std;

int n, m;
int arr[9];

void sol(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (k == 0) {
            arr[k] = i;
            sol(k+1);
        }
        else if (arr[k-1] <= i) {
            arr[k] = i;
            sol(k+1);
        }
    }
}

int main(void) {
    cin >> n >> m;
    sol(0);
}