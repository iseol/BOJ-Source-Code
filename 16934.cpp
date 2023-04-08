#include <iostream>
using namespace std;

int nxt[1000001][26];
int chk[1000001];

int id = 1;

void insert(string &s) {
    int cur = 1;
    bool flag = false;
    string ans = "";
    for (char c : s) {

        if (nxt[cur][c-'a'] == 0) {
            nxt[cur][c-'a'] = ++id;
            if (!flag) ans += c;
            flag = true;
        }
        if (!flag) ans += c;
        cur = nxt[cur][c-'a'];
    }
    chk[cur]++;
    if (chk[cur] > 1) cout << ans << chk[cur] << '\n';
    else cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert(s); // insert and execute answer
    }
}