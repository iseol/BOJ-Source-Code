#include <iostream>
using namespace std;

int b[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> b[i];

        int box = 0;
        int lbox = 0;

        int gp = 0;
        for (int i = 1; i <= n; i++) {
            if (b[i] == 1) {
                if (lbox == 0) box++;
                else lbox--;

                gp++;
            }
            if (b[i] == 2) {
                if (gp == 0) continue;
                lbox = box - ((gp/2) + 1);
            }
        }
        cout << box << '\n';
    }
}