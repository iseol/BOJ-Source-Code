#include <iostream>
#include <vector>
using namespace std;

bool isprime[3005];


int main() {
    int n, k;
    cin >> n >> k;

    fill(isprime+2, isprime+n+1, true);

    for (int i = 2; i <= n; i++) {
        if (!isprime[i]) continue;
        for (int j = i*i; j <= n; j += i) isprime[j] = false;
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isprime[i]) primes.push_back(i);
    }

    int l = primes.size();

    int cnt = 0;
    for (int i = 0; i < l-1; i++) {
        if (isprime[primes[i]+primes[i+1]+1]) cnt++;
    }

    if (cnt >= k) cout << "YES";
    else cout << "NO";
}