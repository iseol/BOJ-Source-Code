#include <iostream>
using namespace std;

typedef long long ll;
bool isprime[246913];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(isprime + 2, isprime + 246912, true);

    for (ll i = 2; i <= 246912; i++) { // erathos
        if (!isprime[i]) continue;
        for (ll j = i*i; j <= 246912; j += i) isprime[j] = false;
    }

    while (1) {
        int n;
        cin >> n;

        if (n == 0) return 0;
        int ans = 0;

        for (int i = n+1; i <= 2*n; i++) {
            if (isprime[i]) ans++;
        }

        cout << ans << '\n';
    }
}