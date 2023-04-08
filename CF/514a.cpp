#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string x;
    cin >> x;

    
    for (int i = 0; x[i] != '\0'; i++) {
        if (i == 0 && x[i] == '9') continue;

        if (x[i] >= '5') {
            int d = 9 - (x[i] - '0');
            x[i] = (char)(d + '0');
        }
    }

    cout << x;
}