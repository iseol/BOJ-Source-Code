#include <iostream>
#include <algorithm>
using namespace std;

char arr[8][8];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cin >> arr[i][j];
            }
        }

        bool found = false;
        for (int i = 0; i < 8; i++) {
            if (found) break;
            [&] () {
                for (int j = 0; j < 8; j++) {
                    if (arr[i][j] == 'R') continue;
                    else return;
                }
                cout << "R\n";
                found = true;
            } ();

        }


        if (found) continue;

        for (int i = 0; i < 8; i++) {
            if (found) break;
            [&] () {
                for (int j = 0; j < 8; j++) {
                    if (arr[j][i] == 'B') continue;
                    else return;
                }
                cout << "B\n";
                found = true;
            } ();

        }
    }
}