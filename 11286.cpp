#include <iostream>
#include <queue>
using namespace std;
struct comp {
    bool operator()(int &a, int &b) {
        if (abs(a) == abs(b)) return a > b;
        else return abs(a) > abs(b);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int, vector<int>, comp> pq;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (x != 0) pq.push(x);
        else if (!pq.empty()) {
            cout << pq.top() << '\n';
            pq.pop();
        }
        else cout << 0 << '\n';
    }
}
