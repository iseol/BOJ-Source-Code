#include <iostream>
#include <queue>
#include <functional>
#define pii pair<int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, a;
    cin >> n >> l;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (int i = 1; i <= n; i++) {
        cin >> a;
        pq.push({a, i});
        while (pq.top().second < i-l+1) pq.pop();
        cout << pq.top().first << ' ';
    }
}