#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt = 0;
    for (char d : s) {
        if (d == '4' || d == '7') cnt++;
    }

    if (cnt == 4 || cnt == 7) cout << "YES";
    else cout << "NO"; 
}