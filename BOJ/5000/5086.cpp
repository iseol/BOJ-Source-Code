#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) return 0;

        if (b % a == 0) cout << "factor\n";
        else if (a % b == 0) cout << "multiple\n";
        else cout << "neither\n";
    }
}