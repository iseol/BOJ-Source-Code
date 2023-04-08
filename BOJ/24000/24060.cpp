#include <iostream>
using namespace std;

int a[500005], tmp[500005];
int k, cnt;
int ans = -1;


void merge(int p, int q, int r) {
    int i = p; int j = q + 1; int t = 1;

    while (i <= q && j <= r) {
        if (a[i] <= a[j]) tmp[t++] = a[i++];
        else tmp[t++] = a[j++];
    }

    while (i <= q) tmp[t++] = a[i++];
    while (j <= r) tmp[t++] = a[j++];

    i = p; t = 1;
    while (i <= r) {
        a[i++] = tmp[t++];
        cnt++;
        if (cnt == k) ans = a[i-1];
    }
}

void merge_sort(int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(p, q);
        merge_sort(q+1, r);
        merge(p, q, r);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> a[i];

    merge_sort(0, n-1);
    cout << ans;
}