#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int snack[1000005];
int n, m;

bool solve(long long x) {
    if (x == 0) return true;  
    long long cur = 0;
    for (int i = 0; i < n; i++) cur += snack[i] / x;
    return cur >= m;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    for (int i = 0; i < n; i++) cin >> snack[i];
    sort(snack, snack+n);

    long long st = 0;
    long long en = *max_element(snack, snack+n);
    while (st < en) {
        long long mid = (st+en+1) / 2;
        if (solve(mid)) st = mid;
        else en = mid-1;
    }
    cout << st;
}