#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        string a, b;
        cin >> a >> b;

        int sa = a.length();
        int sb = b.length();

        int aa, bb;
        if (a[sa-1] == 'S') {
            aa = -1;
            for (int i = 0; i < sa-1; i++) {
                if (a[i] != 'X') break;
                aa--;
            }
        }
        else if (a[sa-1] == 'M') aa = 0;
        else if (a[sa-1] == 'L') {
            aa = 1;
            for (int i = 0; i < sa-1; i++) {
                if (a[i] != 'X') break;
            aa++;
            }
        }

        if (b[sb-1] == 'S') {
            bb = -1;
            for (int i = 0; i < sb-1; i++) {
                if (b[i] != 'X') break;
                bb--;
            }
        }
        else if (b[sb-1] == 'M') bb = 0;
        else if (b[sb-1] == 'L') {
            bb = 1;
            for (int i = 0; i < sb-1; i++) {
                if (b[i] != 'X') break;
                bb++;
            }
        }

        if (aa < bb) cout << '<' << '\n';
        else if (aa == bb) cout << '=' << '\n';
        else if (aa > bb) cout << '>' << '\n';
    }
}