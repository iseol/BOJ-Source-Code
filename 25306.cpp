#include <iostream>
using namespace std;

long long solve(long long x) {
    long long res = 0;
    for (long long i = (x>>2)<<2; i <= x; i++) res ^= i;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a, b, res;
    cin >> a >> b;

    res = solve(b) ^ solve(a-1);
    cout << res;
}