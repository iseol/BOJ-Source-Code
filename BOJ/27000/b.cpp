#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int c = 0;
    for (int i = 0; i < 10; i++) {
        c += ((a%2) ^ (b%2)) * (1<<i);
        a /= 2; b /= 2;
    }

    cout << c;
}