#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        multiset<int> s;
        int k;
        cin >> k;

        char op;
        int num;
        while (k--) {
            cin >> op >> num;
            switch (op) {
                case 'I':
                    s.insert(num);
                    break;
                case 'D': {
                    if (!s.empty()) {
                        if (num == 1) s.erase(--s.end());
                        else s.erase(s.begin());
                    }
                    break;
                }
            }
        }

        if (s.empty()) cout << "EMPTY" << '\n';
        else {
            cout << *s.rbegin() << ' ' << *s.begin() << '\n';
        }
    }
}