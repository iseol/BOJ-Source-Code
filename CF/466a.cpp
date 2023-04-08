#include <iostream>
using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    
    if (a * m < b) cout << a * n;
    else cout << b * (n/m) + min(a*(n%m), b);
}