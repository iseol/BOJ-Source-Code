#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int skip = 0;
    int cnt = 0;
    int sz = s.size();
    for (int i = 0; i < sz; i++) {
        if (skip) {
            skip--;
            continue;
        }
        
        if (i != sz-1) {
            switch (s[i]) {
                case 'c': {
                    if (s[i+1] == '=' || s[i+1] == '-') skip = 1;
                    break; 
                }
                case 'd': {
                    if (i <= sz-2) {
                        if (s[i+1] == 'z' && s[i+2] == '=') skip = 2;
                    }
                    if (s[i+1] == '-') skip = 1;
                    break;
                }
                case 'l': {
                    if (s[i+1] == 'j') skip = 1;
                    break;
                }
                case 'n': {
                    if (s[i+1] == 'j') skip = 1;
                    break;
                }
                case 's': {
                    if (s[i+1] == '=') skip = 1;
                    break;
                }
                case 'z': {
                    if (s[i+1] == '=') skip = 1;
                    break;
                }
            }
        }
        cnt++;
    }
    cout << cnt;


}
