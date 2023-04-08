#include <iostream>
using namespace std;

int cnt[7];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 5 || x == 7) {
            cout << -1;
            return 0;
        } 

        cnt[x]++;
    }

    if (cnt[4] == 0 && cnt[6] == 0) {
        cout << -1;
        return 0;
    }

    
    if (cnt[1] >= cnt[4] && cnt[2] >= cnt[4]) {
        if (cnt[1] - cnt[4] != cnt[6] || cnt[2] - cnt[4] + cnt[3] != cnt[6]) {
            cout << -1;
            return 0;
        }
        else {
            for (int i = 0; i < cnt[4]; i++) cout << 1 << ' ' << 2 << ' ' << 4 << '\n';
            for (int i = 0; i < cnt[2]-cnt[4]; i++) cout << 1 << ' ' << 2 << ' ' << 6 << '\n';
            for (int i = 0; i < cnt[3]; i++) cout << 1 << ' ' << 3 << ' ' << 6 << '\n';
        }

    }
    else {
        cout << -1;
        return 0;
    }
}