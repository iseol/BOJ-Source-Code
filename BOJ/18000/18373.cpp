#include <iostream>
using namespace std;

typedef long long ll;
ll pow(ll a, ll b, ll m) {
    if (b == 1) return a % m;

    ll val = pow(a, b/2, m);
    val = (val * val) % m;

    if (b % 2 == 0) return val;
    else return (a * val) % m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k, p;
    cin >> n >> k >> p;

    if (n == 3) {
        n = 6;
        k--;
    }

    if (n >= p) cout << 0;
    else if (n == 2) cout << 2 % p;
    else if (n >= 4) {
        if (k == 1) {
            long long d = 1;
            for (int i = 1; i <= 6; i++) {
                d *= i;
                d %= p;
            }

            cout << d;
        }
        else if (k == 2) {
            if (n < 12) {
                // f! mod p를 구해야 함.
                long long f = 1;
                for (int i = 2; i <= n; i++) f *= i;
                
                long long fact = 1;
                for (int i = 1; i <= f; i++) {
                    fact *= i;
                    fact %= p;
                }

                cout << fact;
            }
            else if (n == 12) {
                long long f = 1;
                for (int i = 2; i <= n; i++) f *= i;
                
                long long fact = p-1;
                for (int i = p-1; i > f; i--) {
                    fact *= pow(i, p-2, p);
                    fact %= p;
                }

                cout << fact;
            }
            else cout << 0;
        }
        else if (k >= 3) cout << 0;
    }
}