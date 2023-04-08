#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<string, int> m;
    
    while (n--) {
        string name;
        cin >> name;

        if (m.find(name) == m.end()) {
            m[name] = 0;
            cout << "OK\n";
        }
        else {
            m[name]++;
            cout << name << m[name] << '\n';
        }
    }
}