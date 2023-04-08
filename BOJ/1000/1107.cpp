#include <iostream>
using namespace std;

bool button[10];

int main() {
    fill(button, button+10, true);

    int n;
    cin >> n;

    int m;
    cin >> m;
    while (m--) {
        int num;
        cin >> num;
        
        button[num] = false;
    }

    // 100번에서 바로 가는 경우
    int ans = abs(n-100);

    // 버튼을 누르는 경우: 1번
    for (int a = 0; a < 10; a++) {
        if (!button[a]) continue;
        ans = min(ans, 1+abs(n-a));
    }

    // 2번
    for (int a = 1; a < 10; a++) {
        if (!button[a]) continue;
        for (int b = 0; b < 10; b++) {
            if (!button[b]) continue;
            ans = min(ans, 2+abs(n-((10*a)+b)));
        }
    }

    // 3번
    for (int a = 1; a < 10; a++) {
        if (!button[a]) continue;
        for (int b = 0; b < 10; b++) {
            if (!button[b]) continue;
            for (int c = 0; c < 10; c++) {
                if (!button[c]) continue;
                ans = min(ans, 3+abs(n-(100*a + 10*b + c)));
            }
        }
    }

    // 4번
    for (int a = 1; a < 10; a++) {
        if (!button[a]) continue;
        for (int b = 0; b < 10; b++) {
            if (!button[b]) continue;
            for (int c = 0; c < 10; c++) {
                if (!button[c]) continue;
                for (int d = 0; d < 10; d++) {
                    if (!button[d]) continue;
                    ans = min(ans, 4+abs(n-(1000*a + 100*b + 10*c + d)));
                }
            }
        }
    }
    // 5번
    for (int a = 1; a < 10; a++) {
        if (!button[a]) continue;
        for (int b = 0; b < 10; b++) {
            if (!button[b]) continue;
            for (int c = 0; c < 10; c++) {
                if (!button[c]) continue;
                for (int d = 0; d < 10; d++) {
                    if (!button[d]) continue;
                    for (int e = 0; e < 10; e++) {
                        if (!button[e]) continue;
                        ans = min(ans, 5+abs(n-(10000*a + 1000*b + 100*c + 10*d + e)));
                    }
                }
            }
        }
    }
    // 6번
    for (int a = 1; a < 10; a++) {
        if (!button[a]) continue;
        for (int b = 0; b < 10; b++) {
            if (!button[b]) continue;
            for (int c = 0; c < 10; c++) {
                if (!button[c]) continue;
                for (int d = 0; d < 10; d++) {
                    if (!button[d]) continue;
                    for (int e = 0; e < 10; e++) {
                        if (!button[e]) continue;
                        for (int f = 0; f < 10; f++) {
                            if (!button[f]) continue;
                            ans = min(ans, 6+abs(n-(100000*a + 10000*b + 1000*c + 100*d + 10*e + f)));
                        }
                    }
                }
            }
        }
    }

    cout << ans;
}