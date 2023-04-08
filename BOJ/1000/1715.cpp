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

    int temp;
    while (n--) {
        cin >> temp;
        pq.push(temp);
    }

    int ans = 0;
    while (1) {
        if (pq.size() == 1) break;
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        ans += (a+b);
        pq.push(a+b);
    }
    cout << ans;
}
