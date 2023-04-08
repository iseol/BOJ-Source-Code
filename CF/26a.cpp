#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

bool isprime[3005];

int main() {
    int n;
    cin >> n;

    fill(isprime+2, isprime+n+1, true);

    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (!isprime[i]) continue;
        for (int j = i*i; j <= n; j += i) {
            isprime[j] = false;
        }
        primes.push_back(i);
    }

    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        set<int> div;
        for (int j : primes) {
            if (i > j) {
                if (i % j == 0) div.insert(j);
            }
        }
        
        if (div.size() == 2) cnt++;
    }

    cout << cnt;
}