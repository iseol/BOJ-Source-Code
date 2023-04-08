#include <iostream>
#include <unordered_map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_map<string, string> memo;
    int n, m;
    cin >> n >> m;

    string site, pw;
    while (n--) {
        cin >> site >> pw;
        memo[site] = pw;
    }

    string what;
    while (m--) {
        cin >> what;
        cout << memo[what] << '\n';
    }
}