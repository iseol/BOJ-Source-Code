#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<string> kinds;
        string name, kind;
        unordered_map<string, int> cnt; // kind, costumes
        while (n--) {
            cin >> name >> kind;
            if (cnt.find(kind) == cnt.end()) {
                cnt[kind] = 1;
                kinds.push_back(kind);
            }
            else cnt[kind]++;
        }
        long long res = 1;
        for (string k : kinds) {
            res *= (cnt[k]+1);
        }
        res--;
        cout << res << '\n';
    }
}