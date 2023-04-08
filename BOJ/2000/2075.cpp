#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int temp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int, vector<int>, greater<int>> pq;

    int n;
    cin >> n;

    
    for (int i = 0; i < n*n; i++) {
        cin >> temp;
        if (pq.size() == n) {
            if (pq.top() < temp) {
                pq.pop();
                pq.push(temp);
            }
        }
        else pq.push(temp);
        
    }
    vector<int> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    cout << ans[0];
}