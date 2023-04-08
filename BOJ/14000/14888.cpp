#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int num[n];
    for (int i = 0; i < n; i++) cin >> num[i];


    int add, sub, mul, div;
    cin >> add >> sub >> mul >> div;
    vector<int> arr;
    for (int i = 0; i < add; i++) arr.push_back(1);
    for (int i = 0; i < sub; i++) arr.push_back(2);
    for (int i = 0; i < mul; i++) arr.push_back(3);
    for (int i = 0; i < div; i++) arr.push_back(4);
    
    int mx = -1e9 - 7;
    int mn = 1e9 + 7;
    do {
        int sum = num[0];
        for (int i = 0; i < n-1; i++) {
            switch (arr[i]) {
                case 1: {
                    sum += num[i+1];
                    break;
                }
                case 2: {
                    sum -= num[i+1];
                    break;
                }
                case 3: {
                    sum *= num[i+1];
                    break;
                }
                case 4: {
                    sum /= num[i+1];
                    break;
                }
            }
        }
        mx = max(mx, sum);
        mn = min(mn, sum);
    } while (next_permutation(arr.begin(), arr.end()));

    cout << mx << '\n' << mn;
}