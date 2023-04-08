#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    queue<int> q;
    while (1) {
        int what;
        cin >> what;
        if (what == -1) break;

        if (what == 0) q.pop();
        else if (q.size() < n) q.push(what);
    }

    if (q.empty()) cout << "empty";
    else {
        while (!q.empty()) {
            cout << q.front() << ' ';
            q.pop();
        }
    }
}