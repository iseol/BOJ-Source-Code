#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool sol(int k) {
    vector<int> digits;
    for (int i = k; i > 0; i /= 10) {
        digits.push_back(i%10);
    }
    reverse(digits.begin(), digits.end());
    
    int sz = (int)digits.size();
    int diff = digits[0] - digits[1];
    for (int i = 0; i < sz-1; i++) {
        if (digits[i] - digits[i+1] != diff) return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i < 10) cnt++;
        else if (sol(i)) cnt++;
    }

    cout << cnt;
}