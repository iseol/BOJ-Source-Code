#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int n, c;
ll cnt = 0;
int item[30];

vector<ll> group;
void combineleft(int k, ll val) {
    if (k == (n/2)) {
        if (val <= c) group.push_back(val);
        return;
    }

    combineleft(k+1, val);
    combineleft(k+1, val+item[k]);

}

void combineright(int k, ll val) {
    if (k == n) {
        if (val <= c) {
            cnt += upper_bound(group.begin(), group.end(), c - val) - group.begin();
        }
        return;
    }
    combineright(k+1, val);
    combineright(k+1, val+item[k]);



}


int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> item[i];

    combineleft(0, 0);
    sort(group.begin(), group.end());
    combineright(n/2, 0);
    cout << cnt;
}