#include <iostream>
#include <set>
using namespace std;

set<int> s[101];
int no[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int p, l;
    while (n--) {
        cin >> p >> l;
        s[l].insert(p);
        no[p] = l;
    }
    
    int m;
    cin >> m;
    
    string what;
    while (m--) {
        cin >> what;
        if (what == "add") {
            cin >> p >> l;
            s[l].insert(p);
            no[p] = l;
        }
        else if (what == "recommend") {
            int x;
            cin >> x;
            if (x == 1) {
                for (int i = 100; i > 0; i--) {
                    if (s[i].empty()) continue;
                    cout << *s[i].rbegin() << '\n';
                    break;
                }
            }
            else {
                for (int i = 1; i <= 100; i++) {
                    if (s[i].empty()) continue;
                    cout << *s[i].begin() << '\n';
                    break;
                }
            }
        }
        else {
            cin >> p;
            s[no[p]].erase(p);
            no[p] = 0;
        }
    }
}