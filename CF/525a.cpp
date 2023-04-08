#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    map<char, int> m;
    int ans = 0;
    for (int i = 1; i < 2*n-2; i+=2) {
        m[s[i-1]]++;
        if (m[(char)(s[i]+32)] == 0) ans++;
        else {
            m[(char)(s[i]+32)]--;
        }
    }

    cout << ans;
}