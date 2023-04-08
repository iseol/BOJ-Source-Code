#include <iostream>
using namespace std;

int arr[46];

void backtracking(int k) {
    int sum = 0;
    int num = k;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    if (arr[sum] > k) arr[sum] = k;
    for (int i = (k%10) + 1; i <= 9; i++) {
        backtracking(k*10+i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(arr, arr+46, 123456790);
    for (int i = 1; i <= 9; i++) backtracking(i);

    int tc;
    cin >> tc;

    while (tc--) {
        int s;
        cin >> s;
        cout << arr[s] << '\n';
    }
}