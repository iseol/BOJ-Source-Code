#include <cstdio>
using namespace std;

__int128 arr[36];

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
bool cmp(__int128 x, __int128 y) { return x > y; }

int main() {
    int n;
    scanf("%d", &n);

    arr[0] = 1;
    for (int i = 1; i <= 35; i++) {
        for (int j = 0; j < i; j++) arr[i] += arr[i-j-1]*arr[j];
    }

    print(arr[n]);
}