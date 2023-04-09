#include <iostream>
using namespace std;

int ask(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);

    int ans;
    scanf("%d", &ans);
    return ans;
}

void give(int x, int y) {
    printf("! %d %d\n", x, y);
    fflush(stdout);
}

int main() {

    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n, m;
        scanf("%d %d", &n, &m);

        int k = ask(1, 1);
        if (k >= n) {
            int p = ask(1, k+1);
            give(p+1, k+1);
        }
        else if (k >= m) {
            int q = ask(k+1, 1);
            give(k+1, q+1);
        }
        else {
            int p = ask(1, k+1);
            int q = ask(k+1, 1);

            if (p == k && q == k) give(k+1, k+1);
            else if (p < k) give(p+1, k+1);
            else give(k+1, q+1);
        }
    }
}