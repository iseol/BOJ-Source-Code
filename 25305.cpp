#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    
    int cur = n;
    while (k--) {
        cur--;
    } 
    cout << arr[cur];
}