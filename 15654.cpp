#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int seq[8];
int arr[8];
bool isused[8];

void sol(int k) {
  if (k == m) {
    for (int i = 0; i < m; i++) cout << seq[i] << ' ';
    cout << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!isused[i]) {
      isused[i] = true;
      seq[k] = arr[i];
      sol(k+1);
      isused[i] = false;
    }
  }
  
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr+n);
  sol(0);
}