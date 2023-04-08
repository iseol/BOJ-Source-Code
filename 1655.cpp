#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq1; // 최솟값 힙
    priority_queue<int> pq2; // 최댓값 힙

    int temp;
    while (n--) {
        cin >> temp;
        if (pq1.size() == pq2.size()) pq2.push(temp);
        else pq1.push(temp);

        if (!pq1.empty()) {
            if (pq1.top() < pq2.top()) {
                int tmp;
                tmp = pq1.top();
                pq1.pop(); pq1.push(pq2.top());
                pq2.pop(); pq2.push(tmp);
            }
        }
        
         
        cout << pq2.top() << '\n';
    }
}