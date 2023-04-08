#include <iostream>
using namespace std;

bool isprime[10001];

int main() {
    fill(isprime+2, isprime+10000, true);
    for (int i = 2; i <= 10000; i++) {
        if (!isprime[i]) continue;
        for (int j = 2*i; j <= 10000; j+=i) isprime[j] = false;
    }

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        int res1 = n/2;
        int res2 = (n+1)/2;
        while (res1 >= 2) {
            if (isprime[res1] && isprime[res2] && res1+res2 == n) {
                cout << res1 << ' ' << res2 << '\n';
                break;
            }
            res1--;
            res2++;
        }        
    }
}