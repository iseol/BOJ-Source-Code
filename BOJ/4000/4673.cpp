#include <iostream>
using namespace std;

bool arr[10001];

int sol(int k) {
    int sum = k;
    for (int i = k; i > 0; i /= 10) {
        sum += i%10;
    }
    return sum;
}

int main() {
    for (int i = 1; i <= 10000; i++) arr[sol(i)] = true;
    for (int i = 1; i <= 10000; i++) {
        if (!arr[i]) cout << i << '\n';
    }
}