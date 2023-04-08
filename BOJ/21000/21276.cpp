#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> adj[1001];
int deg[1001];
unordered_map<string, int> um;
string arr[1001];
vector<int> res[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n;

    string name[1001];
    for (int i = 0; i < n; i++) cin >> name[i];
    sort(name, name+n);
    for (int i = 1; i <= n; i++) {
        um[name[i-1]] = i;
        arr[i] = name[i-1];
    }

    cin >> m;
    while (m--) {
        string temp1, temp2;
        cin >> temp1 >> temp2;
        adj[um[temp2]].push_back(um[temp1]);
        deg[um[temp1]]++;
    }

    int k = 0;
    queue<int> q;
    vector<int> st;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            k++;
            st.push_back(i);
        }
    }

    for (int x : st) {
        queue<int> q;
        q.push(x);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt : adj[cur]) {
                deg[nxt]--;
                if (deg[nxt] == 0) {
                    res[cur].push_back(nxt);
                    q.push(nxt);
                }
            }
        }
    }

    cout << k << '\n';
    for (int x : st) cout << arr[x] << ' ';
    cout << '\n';

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ' << res[i].size() << ' ';
        sort(res[i].begin(), res[i].end());
        for (int x : res[i]) {
            cout << arr[x] << ' ';
        }
        cout << '\n';
    }

}