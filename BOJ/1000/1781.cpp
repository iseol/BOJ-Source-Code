#include <iostream>
#include <queue>
using namespace std;

struct comp {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        if (a.first == b.first) return a.second < b.second;
        else return a.first > b.first;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<pair<int, int>, vector<pair<int, int> >, comp> pq;

    int n;
    cin >> n;

    int d, c; // deadline, cup ramyeon
    while (n--) {
        cin >> d >> c;
        pq.push({d, c});
    }

    int time = 1;
    priority_queue<int, vector<int>, greater<int>> ans;
    /* while (!pq.empty()) {
        cout << pq.top().first << ' ' << pq.top().second << '\n';
        pq.pop();
    } */
    
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (cur.first >= time) {
            ans.push(cur.second);
            time++;
        }
        else {
            if (ans.top() < cur.second) {
                ans.pop();
                ans.push(cur.second);
            }
        }
    }

    int res = 0;
    while (!ans.empty()) {
        res += ans.top();
        ans.pop();
    }
    cout << res; 
}