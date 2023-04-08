#include <iostream>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            
            q.push({i, temp});
            pq.push(temp);
        }

        int time = 0;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (pq.top() == cur.second) {
                pq.pop();
                time++;
                
                if (cur.first == m) {
                    cout << time << '\n';
                    break; 
                }
            }
            else q.push(cur);

        }
    }
}