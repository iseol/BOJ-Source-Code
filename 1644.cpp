#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 4'000'000;
bool isprime[4'000'005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(isprime+2, isprime+MAXN+1, true);

    for (ll i = 2; i <= 4'000'000; i++) {
        if (!isprime[i]) continue;
        for (ll j = i*i; j <= 4'000'000; j += i) {
            isprime[j] = false;
        }
    }

    vector<int> prime;
    for (int i = 2; i <= MAXN; i++) {
        if (isprime[i]) prime.push_back(i);
    }

    int pn = prime.size();
    
    int n;
    cin >> n;

    int en = 0; ll sum = prime[0];
    int ans = 0;
    for (int st = 0; st < pn; st++) {
        while (en < pn && sum < n) {
            en++;
            if (en != pn) sum += prime[en];
        }
        if (en == pn) break;

        if (sum == n) ans++;
        sum -= prime[st];
    }

    cout << ans;
}