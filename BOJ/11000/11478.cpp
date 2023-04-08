#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_set<string> us;
    int sz = (int)s.size();
    string ss = "";
    for (int i = 0; i < sz; i++) { // start
        for (int j = i; j < sz; j++) {
            ss += s[j];
            us.insert(ss);
        }
        ss = "";
    }

    cout << us.size();
}