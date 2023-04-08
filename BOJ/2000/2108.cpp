#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int freq[8001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int mx = -4001;
    int mn = 4001;
    double sum = 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        freq[arr[i]+4000]++;
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }

    double average = floor(sum / n + 0.5);
    int diff = mx - mn;
    sort(arr, arr+n);
    int median = arr[(n-1)/2];
    int mode;
    
    int mxfreq = -1;
    for (int i = 0; i < 8001; i++) mxfreq = max(mxfreq, freq[i]);
    vector<int> mxfreqs;
    for (int i = 0; i < 8001; i++) {
        if (freq[i] == mxfreq) mxfreqs.push_back(i-4000);
    }
    sort(mxfreqs.begin(), mxfreqs.end());
    if (mxfreqs.size() < 2) mode = mxfreqs[0];
    else mode = mxfreqs[1];

    cout << average << '\n';
    cout << median << '\n';
    cout << mode << '\n';
    cout << diff;
}