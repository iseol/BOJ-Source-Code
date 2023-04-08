#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);

    cout << '<';
    while (!q.empty()) {
        for (int i = 1; i < k; i++) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        

        if (q.size() == 1) cout << q.front();
        else cout << q.front() << ", ";
        q.pop();
    }
    cout << '>';
}