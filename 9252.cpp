#include <iostream>
#include <vector>
using namespace std;

int d[1001][1001];

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.length();
    int l2 = s2.length();

    int res = -1;
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i-1] == s2[j-1]) {
                d[i][j] = d[i-1][j-1] + 1;
            }
            else {
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
            res = max(res, d[i][j]);
        }
    }
    cout << res << '\n';
    vector<char> ans;
    int i, j;
    [&] () {
        for (i = 1; i <= l1; i++) {
            for (j = 1; j <= l2; j++) {
                if (d[i][j] == res) return;
            }
        }
    } ();


    while (i >= 1 && j >= 1) {
        if (d[i-1][j] == d[i][j]) i--;
        else if (d[i][j-1] == d[i][j]) j--;
        else {
            ans.push_back(s1[i-1]);
            i--; j--;
        }
    }

    while (!ans.empty()) {
        cout << ans.back();
        ans.pop_back();
    }
}