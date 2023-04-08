#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> arr[100001];

int main() {
    int n;
    cin >> n;
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int st, en;
        cin >> st >> en;
        arr[i] = {en, st};
    }

    sort(arr, arr+n);

    int t = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].second >= t) {
            t = arr[i].first;
            ans++;
        }
    }
    cout << ans;
}