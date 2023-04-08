#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n; 
        cin >> n;

        string s;
        cin >> s;

        bool flag = false;

        set<string> se;
        map<string, int> idx;
        for (int i = 0; i < n-1; i++) {
            string ss(1, s[i]);
            ss += s[i+1];
            
            if (se.find(ss) == se.end()) {
                se.insert(ss);
                idx[ss] = i;
            }
            else if (idx[ss] < i-1) {
                flag = true;
                break;
            } 
        }

        if (flag) cout << "YES\n";
        else cout << "NO\n";
        
    }
}