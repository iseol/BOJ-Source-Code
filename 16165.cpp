#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<string>> zero;
unordered_map<string, string> one;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    while (n--) {
        string group;
        cin >> group;
        

        int p;
        cin >> p;
        while (p--) {
            string m;
            cin >> m;
            
            zero[group].push_back(m);
            one[m] = group;
        }
        sort(zero[group].begin(), zero[group].end());
    }

    while (m--) {
        string what;
        cin >> what;
        bool q;
        cin >> q;

        if (q) { // one
            cout << one[what] << '\n';
        }
        else {
            for (string s : zero[what]) cout << s << '\n';
        }
    }
}