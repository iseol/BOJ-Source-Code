#include <iostream>
#include <queue>
using namespace std;

int dist[10000];
string command[10000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        fill(dist, dist+10000, -1);
        fill(command, command+10000, "");
        int a, b;
        cin >> a >> b;

        dist[a] = 0;
        queue<int> q;
        
        q.push(a);

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            int nxt;
            
            // D
            nxt = (cur*2)%10000;
            if (dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
                command[nxt] = (command[cur] + 'D');
            }

            // S
            if (cur == 0) nxt = 9999;
            else nxt = cur - 1;
            if (dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
                command[nxt] = (command[cur] + 'S');
            }

            // L
            nxt = ((cur/100)%10)*1000 + ((cur/10)%10)*100 + (cur%10)*10 + (cur/1000);
            if (dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
                command[nxt] = (command[cur] + 'L');
            }

            // R
            nxt = (cur%10)*1000 + (cur/1000)*100 + ((cur/100)%10)*10 + ((cur/10)%10);
            if (dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
                command[nxt] = (command[cur] + 'R');
            }
        }

        cout << command[b] << '\n';
    }
}