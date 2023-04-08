#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int s[20][20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }

    int res = 1e7;
    vector<int> arr;
    for (int i = 0; i < n/2; i++) arr.push_back(0);
    for (int i = 0; i < n/2; i++) arr.push_back(1);

    do {
        vector<int> group1, group2;
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (!arr[i]) group1.push_back(i);
            else group2.push_back(i);
        }
        for (int i : group1) {
            for (int j : group1) {
                sum1 += s[i][j];
            }
        }
        
        for (int i : group2) {
            for (int j : group2) {
                sum2 += s[i][j];
            }
        }

        res = min(res, abs(sum1-sum2));
    } while (next_permutation(arr.begin(), arr.end()));
    cout << res;
}