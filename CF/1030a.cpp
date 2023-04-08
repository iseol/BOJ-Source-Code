#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        int q;
        cin >> q;

        if (q == 1) {
            cout << "HARD";
            return 0;
        }
    }
    cout << "EASY";
}