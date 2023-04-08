#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
int seq[8];

void sol(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) cout << seq[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (k == 0) {
            seq[k] = arr[i];
            sol(k+1);
        }
        else if (seq[k-1] <= arr[i]) {
            seq[k] = arr[i];
            sol(k+1);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    sol(0);
}