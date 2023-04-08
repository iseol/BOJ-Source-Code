#include <iostream>

using namespace std;

int n, num;
int arr[21];

int fibo(int n) {
  if (n >= 2) {
    return fibo(n-1) + fibo(n-2);
  } else {
    return n;
  }
}

int main(void) {
  cin >> num;
  cout << fibo(num) << '\n';
}
