#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;

        int l = s.length();

        
        if (s[0] == 'a' && s[l-1] == 'a') {
            cout << "a ";
            for (int i = 1; i < l-1; i++) cout << s[i];
            cout << " a";
            
            cout << '\n';
        }
        else if (s[0] == 'b' && s[l-1] == 'b') {
            cout << "b ";
            for (int i = 1; i < l-1; i++) cout << s[i];
            cout << " b";
            
            cout << '\n';
        }
        else {
            int k = -1;
            for (int i = 1; i < l-1; i++) {
                if (s[i] == 'a') {
                    k = i;
                    break;
                }
            }

            if (k == -1) {
                cout << s[0] << ' ';
                for (int i = 1; i < l-1; i++) cout << s[i];
                cout << ' ' << s[l-1];

                cout << '\n';
            }
            else {
                for (int i = 0; i < k; i++) cout << s[i];
                cout << ' ';
                cout << s[k];
                cout << ' ';
                for (int i = k+1; i < l; i++) cout << s[i];
                
                cout << '\n';
            }
            
        }
    }
}