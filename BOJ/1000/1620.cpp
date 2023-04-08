#include <iostream>
#include <unordered_map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    unordered_map<string, string> mp;
    
    string name;
    for (int i = 1; i <= n; i++) {
        cin >> name;
        mp[name] = to_string(i);
        mp[to_string(i)] = name;
    }

    string what;
    while (m--) {
        cin >> what;
        cout << mp[what] << '\n';
    }
}
