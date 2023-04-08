#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    unordered_set<string> s;
    while (n--) {
        string name, state;
        cin >> name >> state;
        if (state == "enter") s.insert(name);
        else s.erase(name);
    }
    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for (string e : ans) cout << e << '\n';
}