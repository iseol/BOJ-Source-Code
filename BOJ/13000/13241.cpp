#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    
    ll r = a % b;
    return gcd(b, r); 
}

int main() {
    ll a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    cout << a * b / gcd(a, b);
}