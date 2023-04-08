#include <iostream>
#include <string>
using namespace std;

int d[26][200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int sz = (int)s.size();

    for (int i = 0; i < 26; i++) {
        char find = i + 'a';
        for (int j = 0; j < sz; j++) {
            d[i][j+1] = d[i][j];
            if (find == s[j]) d[i][j+1]++;
        }
    }
    int q;
    cin >> q;
    
    while (q--) {
        char a;
        int l, r;
        cin >> a >> l >> r;

        cout << d[a-'a'][r+1] - d[a-'a'][l] << '\n';
    }
}