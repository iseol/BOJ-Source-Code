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

        int al = a.length();
        int bl = b.length();

        if (a[0] == b[0]) {
            cout << "YES" << '\n';
            cout << a[0] << '*' << '\n';
            continue;
        }
        else if (a[al-1] == b[bl-1]) {
            cout << "YES" << '\n';
            cout << '*' << a[al-1] << '\n';
            continue;
        }

        int l = a.length();
        bool flag = false;
        for (int i = 0; i < l-1; i++) {
            string temp = "";
            temp += a[i];
            temp += a[i+1];

            if (b.find(temp) != string::npos) {
                flag = true;
                cout << "YES" << '\n';
                cout << '*' << temp << '*' << '\n';
                break;
            }
        }
        if (!flag) cout << "NO" << '\n';
    }
}