#include <iostream>
#include <algorithm>
using namespace std;

bool illegal[100005];

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

        for (int i = 0; i < n/2; i++) {
            if (s[i] != s[n-i-1]) illegal[i] = true;
        }

        bool flag1 = false;
        bool flag2 = false;
        [&] () {
            for (int i = 0; i < n/2; i++) {
                if (illegal[i]) {
                    flag1 = true;
                    
                }
                if (flag1 && !illegal[i]) {
                    flag2 = true;
                }
                if (flag2 && illegal[i]) {
                    cout << "No" << '\n';
                    return;
                }
            }
            cout << "Yes" << '\n';
        } ();
        fill(illegal, illegal+n, false);
    }
}