#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isprime[100005];

int main() {
    int n;
    cin >> n;

    fill(isprime+2, isprime+n+2, true);

    for (long long i = 2; i <= n+1; i++) {
        if (!isprime[i]) continue;
        for (long long j = i*i; j <= n+1; j += i) {
            isprime[j] = false;
        } 
    }


    if (n <= 2) cout << "1\n";
    else cout << "2\n";

    for (int i = 2; i <= n+1; i++) {
        if (i <= (n+1)/2) {
            if (isprime[i]) cout << "2 ";
            else cout << "1 ";
        }
        else cout << "1 ";
    }
}