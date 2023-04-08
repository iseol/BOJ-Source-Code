#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 10) {
        cout << 9;
        return 0;
    }

    int ans = 1;
    while (1) {
        n++;
        while (n % 10 == 0) n /= 10;

        
        if (n < 10) {
            ans += 9;
            break;
        }
        else ans++;
    }
    cout << ans;

}