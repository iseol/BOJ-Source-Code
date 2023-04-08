#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[200010];
bool flag = false;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        if (flag) return a.second < b.second;
        else return a.second > b.second;
    }
    return a < b;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        s = '@' + s;

        int sz = (s.length()) - 1;

        for (int i = 1; i <= sz; i++) {
            arr[i] = {s[i]-'a'+1, i};
        }
        int cost = abs(arr[1].first-arr[sz].first);
        if (arr[1].first < arr[sz].first) flag = true;

        sort(arr+1, arr+sz+1, comp);
        /*for (int i = 1; i <= sz; i++) {
            cout << arr[i].first << ' ' << arr[i].second << '\n';
        }*/

        int st;
        int en;
        for (int i = 1; i <= sz; i++) {
            if (arr[i].second == 1) st = i;
            if (arr[i].second == sz) en = i;
        }

        vector<int> path;

        if (st < en) {
            for (int i = st; i <= en; i++) {
                path.push_back(arr[i].second);
            }
        }
        else {
            for (int i = st; i >= en; i--) {
                path.push_back(arr[i].second);
            }
        }
        
        cout << cost << ' ' << path.size() << '\n';
        for (int x : path) cout << x << ' ';
        cout << '\n';
        flag = false;
    }
}