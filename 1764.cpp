#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    unordered_set<string> us;
    cin >> n >> m;
    while (n--) {
        string temp;
        cin >> temp;
        us.insert(temp);
    }

    int cnt = 0;
    vector<string> ans;
    while (m--) {
        string temp;
        cin >> temp;
        if (us.find(temp) != us.end()) {
            cnt++;
            ans.push_back(temp);
        }
    }

    sort(ans.begin(), ans.end());
    cout << cnt << '\n';
    for (string s: ans) cout << s << '\n';
}