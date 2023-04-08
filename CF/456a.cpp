#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> c[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        c[i] = {a, b};
    }

    sort(c, c+n);
    
    for (int i = 0; i < n-1; i++) {
        if (c[i].first < c[i+1].first && c[i].second > c[i+1].second) {
            cout << "Happy Alex";
            return 0;
        }
    }

    cout << "Poor Alex";

}