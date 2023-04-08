#include <iostream>
using namespace std;

int w[50], h[50], res[50]; // weight, height, result

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> w[i] >> h[i];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            if (w[i] < w[j] && h[i] < h[j]) res[i]++;
        }
    }

    for (int i = 0; i < n; i++) cout << res[i]+1 << ' ';
}