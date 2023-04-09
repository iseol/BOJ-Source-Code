#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        if (((x1 == 1 || x1 == n) && (y1 == 1 || y1 == m)) || (x2 == 1 || x2 == n) && (y2 == 1 || y2 == m)) cout << "2\n";
        else if (((x1 == 1 || x1 == n) || (y1 == 1 || y1 == m)) || ((x2 == 1 || x2 == n) || (y2 == 1 || y2 == m))) cout << "3\n";
        else cout << "4\n";
    }
}