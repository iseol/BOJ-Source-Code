#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        long long n;
        cin >> n;
        
        cout << (int)(sqrtl(n-1)) << '\n';
    }
}