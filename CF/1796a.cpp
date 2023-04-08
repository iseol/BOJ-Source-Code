#include <iostream>
using namespace std;

string fb = "FBFFBFFBFBFFBFFBFBFFBFFB";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        int k;
        cin >> k;

        string s;
        cin >> s;

        cout << (fb.find(s) != string::npos ? "YES" : "NO") << '\n';
        
    }
}