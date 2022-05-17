#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    while (1) {
        string str1, str2;
        cin >> str1;
        if (str1 == "0") return 0;
        str2 = str1;
        reverse(str2.begin(), str2.end());
        if (str1 == str2) {
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }
}
