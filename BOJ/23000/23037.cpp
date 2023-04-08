#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int sum = 0;
    for (char c : s) {
        sum += (c-'0')*(c-'0')*(c-'0')*(c-'0')*(c-'0');
    }
    cout << sum;
}