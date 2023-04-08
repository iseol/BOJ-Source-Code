#include <iostream>
#include <algorithm>
using namespace std;

int a[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int p = a[0] % 2;
    
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (p != a[i] % 2) flag = true; 
    }
    if (!flag) {
        for (int i = 0; i < n; i++) cout << a[i] << ' ';
        return 0;
    }
    

    sort(a, a+n);
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
}