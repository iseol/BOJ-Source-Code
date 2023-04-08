#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    int ans = 0;

    for (int i = 0; i < 4; i++) {
        int h;
        cin >> h;

        if (s.find(h) == s.end()) s.insert(h);
        else ans++;
    }

    cout << ans;
}