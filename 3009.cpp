#include <iostream>
using namespace std;

int cntx[1001], cnty[1001];

int main() {
    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        cntx[x]++;
        cnty[y]++;
    }

    int x, y;
    for (int i = 1; i <= 1000; i++) {
        if (cntx[i] == 1) x = i;
        if (cnty[i] == 1) y = i;
    }

    cout << x << ' ' << y;
}