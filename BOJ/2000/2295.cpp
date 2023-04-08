#include <iostream>
#include <algorithm>
using namespace std;

int arr[1005], two[1010101];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            two[idx] = arr[i] + arr[j];
            idx++;
        }
    }

    sort(two, two+n*(n-1));
    for (int k = n-1; k >= 0; k--) {
        for (int z = 0; z < k; z++) {
            if (binary_search(two, two+n*(n-1), arr[k]-arr[z])) {
                cout << arr[k];
                return 0;
            }
        }
    }
}