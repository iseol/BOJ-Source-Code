#include <iostream>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        int l = (int)s.size();
        cout << s[0] << s[l-1] << '\n';
    }
}