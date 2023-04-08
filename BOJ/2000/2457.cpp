#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> flower[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int st1, st2, en1, en2;
        cin >> st1 >> st2 >> en1 >> en2;
        flower[i] = {100*st1 + st2,  100*en1 + en2};
    }

    sort(flower, flower+n);
    
    /*for (int i = 0; i < n; i++) {
        cout << flower[i].first << ' ' << flower[i].second << '\n';
    }*/

    int now = 301;
    int nxt = 0;
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (flower[i].first > now) {
            if (nxt == 0) {
                cout << 0;
                return 0;
            }
            now = nxt;
            ans++;
            if (now > 1130) break;
        }

        if (flower[i].first <= now) nxt = max(nxt, flower[i].second);
    }
    if (now != nxt) {
        now = nxt;
        ans++;
    }

    if (now > 1130) cout << ans;
    else cout << 0;
}