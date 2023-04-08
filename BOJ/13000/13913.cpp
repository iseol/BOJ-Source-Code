#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dist[200002];
int pn[200002];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    fill(dist, dist+200002, -1);

    dist[n] = 0;
    pn[n] = -1;
    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        if (cur-1 >= 0 && dist[cur-1] == -1) {
            dist[cur-1] = dist[cur]+1;
            pn[cur-1] = cur;
            q.push(cur-1);
        }
        if (cur+1 <= 100000 && dist[cur+1] == -1) {
            dist[cur+1] = dist[cur]+1;
            pn[cur+1] = cur;
            q.push(cur+1);
        }
        if (cur*2 <= 100000 && dist[cur*2] == -1) {
            
            dist[cur*2] = dist[cur]+1;
            pn[cur*2] = cur;
            q.push(cur*2);
        }
    }

    cout << dist[k] << '\n'; 
    vector<int> ans;
    ans.push_back(k);
    while (1) {
        if (pn[k] == -1) break; 
        ans.push_back(pn[k]);
        k = pn[k];
    }
    for (int i = (int)ans.size()-1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
}