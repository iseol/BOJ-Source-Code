#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
int seq[8];
bool isused[8];

void sol(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) cout << seq[i] << ' ';
        cout << '\n';
        return;
    }

    int last = -1;
    for (int i = 0; i < n; i++) {
        if (last != arr[i] && !isused[i]) {
            seq[k] = arr[i];
            isused[i] = true;
            sol(k+1);
            last = arr[i];
            isused[i] = false;
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