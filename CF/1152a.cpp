#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int oc = 0, ec = 0, ok = 0, ek = 0;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        
        if (c % 2 == 0) ec++;
        else oc++;
    }
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        
        if (k % 2 == 0) ek++;
        else ok++;
    }
    cout << min(oc, ek) + min(ec, ok);

    
}