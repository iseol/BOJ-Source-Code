#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int cn = n;

        int x = 0;
        int y = 0;

        int cnt = 0;
        for (int i = 1; i <= cn; i *= 10) {
            if ((n % 10) % 2 == 0) {
                x += i * ((n % 10) / 2);
                y += i * ((n % 10) / 2);
            }
            else {
                if (cnt % 2 == 0) {
                    x += i * (((n % 10) + 1) / 2);
                    y += i * (((n % 10) - 1) / 2);
                }
                else {
                    x += i * (((n % 10) - 1) / 2);
                    y += i * (((n % 10) + 1) / 2);
                }
                cnt++;
            }
            n /= 10;
        }
            
        cout << x << ' ' << y << '\n';
    }
    
    
}