#include <iostream>
using namespace std;

int main() {
    int fn, n;
    int cnt = 0;
    cin >> fn;
    n = fn;
    do {
        n = ((n%10) * 10) + (((n/10) + (n%10))%10);
        cnt++;
    } while (fn != n);

    cout << cnt;
}