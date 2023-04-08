#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;

    queue<pair<int, int> > q;
    q.push({a, 1});

    while (!q.empty()) {
        long long int k, n;
        tie(k, n) = q.front(); q.pop();
        
        if (k == b) {
            cout << n;
            return 0;
        }

        if (k*2 <= b) q.push({k*2, n+1});
        if (10*k +1 <= b) q.push({10*k+1, n+1});
    }
    cout << -1;
}