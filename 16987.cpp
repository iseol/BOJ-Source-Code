#include <iostream>
#define d first 
#define w second
using namespace std;

pair<int, int> eggs[8];
int res = -1;
int n, cnt;

void sol(int cur) {
    if (cur == n) {
        res = max(res, cnt);
        return;
    }
    if (cnt == n-1 || eggs[cur].d <= 0) {
        sol(cur+1);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (i == cur) continue;
        if (eggs[i].d <= 0) continue;
        eggs[i].d -= eggs[cur].w;
        eggs[cur].d -= eggs[i].w;
        if (eggs[cur].d <= 0) cnt++;
        if (eggs[i].d <= 0) cnt++;
        sol(cur+1);
        if (eggs[cur].d <= 0) cnt--;
        if (eggs[i].d <= 0) cnt--;
        eggs[i].d += eggs[cur].w;
        eggs[cur].d += eggs[i].w;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> eggs[i].d >> eggs[i].w;

    sol(0);
    cout << res;
}