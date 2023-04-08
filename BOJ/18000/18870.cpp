#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;
int seq[1000005];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> seq[i];
        arr.push_back(seq[i]);
    }
    
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for (int i = 1; i <= n; i++) cout << lower_bound(arr.begin(), arr.end(), seq[i]) - arr.begin() << ' ';
}