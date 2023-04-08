#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    int x;
    while (n--) {
        cin >> x;
        if (x != 0) pq.push(x);
        else {
            if (pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
}