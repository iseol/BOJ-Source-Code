#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_set<string> us;
    while (n--) {
        string temp;
        cin >> temp;
        us.insert(temp);
    }

    int cnt = 0;
    while (m--) {
        string temp;
        cin >> temp;
        if (us.find(temp) != us.end()) cnt++;
    }
    cout << cnt;
}
