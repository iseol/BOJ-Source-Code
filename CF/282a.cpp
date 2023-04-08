#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int x = 0;
    while (n--) {
        string p;
        cin >> p;
        if (p[0] == '+') x++;
        else if (p[0] == '-') x--;
        
        if (p[2] == '+') x++;
        else if (p[2] == '-') x--;
    }
    cout << x;
}