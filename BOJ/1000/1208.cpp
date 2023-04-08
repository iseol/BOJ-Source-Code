#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int arr[40];
int n, s;
long long res = 0;
map<int, int> m;
//vector<int> group;
void left(int k, int val) {
    if (k == n/2) {
        m[val]++;
        //group.push_back(val);
        return;
    }

    left(k+1, val);
    left(k+1, val+arr[k]);
}

void right(int k, int val) {
    if (k == n) {
        res += m[s-val];
        //int idx_u = upper_bound(group.begin(), group.end(), s-val)-1 - group.begin();
        //int idx_l = lower_bound(group.begin(), group.end(), s-val) - group.begin();
        //if (s-group[idx_u] == val && s-group[idx_l] == val) res += idx_u - idx_l + 1;
        return;
    }

    right(k+1, val);
    right(k+1, val+arr[k]);
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> arr[i];

    left(0, 0);
    //sort(group.begin(), group.end());
    right(n/2, 0);
    if (s == 0) cout << res-1;
    else cout << res;
}