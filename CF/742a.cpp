#include <iostream>
using namespace std;

int main() {
    string s = "6842";
    int n;
    cin >> n;

    if (n == 0) cout << 1;
    else cout << s[n%4];
}