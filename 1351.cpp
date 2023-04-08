#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<long long, long long> d;
long long n, p, q;

long long solve(long long i) {
    if (d[i] != 0) return d[i];

    return d[i] = solve(i / p) + solve(i / q);
}

int main() {
    cin >> n >> p >> q;
    d[0] = 1;
    cout << solve(n);
}