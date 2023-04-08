#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    vector<ll> border;
    for (ll i = 0;; i++) {
        border.push_back(i*(i-1)*3 + 1);
        if (i*(i-1)*3 + 1 >= 1000000000) break;
    }
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    int sz = border.size();
    for (int i = 0; i < sz; i++) {
        if (n <= border[i]) {
            cout << i;
            return 0;
        }
    }
}