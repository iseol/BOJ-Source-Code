#include <iostream>
#include <numeric>
using namespace std;

int sp[100000]; // 간격

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int st, rst; // 시작점, 시작점 보존
    cin >> st; rst = st;

    for (int i = 0; i < n-2; i++) {
        int pos;
        cin >> pos;

        sp[i] = pos - st; // 간격 계산
        st = pos;
    }

    int en; // 끝점
    cin >> en;
    sp[n-1] = en - st;

    int s = gcd(sp[0], sp[1]);
    for (int i = 0; i < n-1; i++) s = gcd(s, sp[i]);

    int trees = ((en - rst) / s) + 1;
    cout << trees - n;
}