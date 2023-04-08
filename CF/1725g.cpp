#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


int main() {
    /*ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr;
    for (int b = 2; b <= 100; b++) {
        for (int a = 1; a < b; a++) {
            arr.push_back((b-a)*(b+a));
        }
    }
    sort(arr.begin(), arr.end());
    for (int k : arr) cout << k << ' ';*/
    
    /*for (int i = 2; i <= 100; i++)
    cout << 4 + floor((4*i-3)/3) << ' ';*/

    long long n;
    cin >> n;
    if (n == 1) cout << 3;
 
    else cout << 4 + (4*n-3)/3;
}