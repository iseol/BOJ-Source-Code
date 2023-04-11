#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        long long a, b, c;
        cin >> a >> b >> c;

        int val;
        bool flag = false;

        val = 2*b - a;
        if (val >= c && val % c == 0) flag = true;
        
        if ((a+c) % 2 == 0) {
            val = (a+c) / 2;
            if (val >= b && val % b == 0) flag = true;
        }

        val = 2*b - c;
        if (val >= a && val % a == 0) flag = true;

        cout << ((flag) ? "YES\n" : "NO\n");
    } 
    
}