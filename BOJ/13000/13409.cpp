#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int res = 0;

typedef long long ll;
int n;
string pile[40];
pair<ll, int> value[40];

vector<pair<ll, int>> group;

bool comp(const pair<ll, int> &a, const pair<ll, int> &b){
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

void left(int k, ll val, int sel) {
    if (k == n/2) {
        group.push_back({val, sel});
        return;
    }

    left(k+1, val, sel);
    left(k+1, val+value[k].first, sel+value[k].second);
}

void right(int k, ll val, int sel) {
    if (k == n) {
        pair<ll, int> p = {-val+1, -1};
        int idx = lower_bound(group.begin(), group.end(), p, comp)-1 - group.begin();
        
        if (group[idx].first + val == 0) {
            //cout << group[idx].second + sel << ' ';
            res = max(res, group[idx].second + sel);
        }
        return;
    }

    right(k+1, val, sel);
    right(k+1, val+value[k].first, sel+value[k].second);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> pile[i];

    int idx = 0;
    for (string s : pile) {
        ll cur = 1;
        ll val = 0;
        char col = s[0]; // W -> +1, B -> -1
        bool changed = false;
        for (char c : s) {
            if (c != col) {
                col = c;
                changed = true;
            }
            if (changed) cur *= 2;
            if (c == 'W') val += (1LL<<40) / cur;
            else val += -1 * ((1LL<<40) / cur);
        }
        value[idx] = {val, s.length()};
        idx++;
    }

    
    left(0, 0, 0);
    sort(group.begin(), group.end());
    //for (auto v : group) cout << v.first << ' ' << v.second << '\n'; 
    right(n/2, 0, 0);

    /*for (int i = 0; i < n; i++) cout << value[i] << ' ';
    cout << '\n';
    for (ll v : group) cout << v << ' ';*/
    cout << res;
}