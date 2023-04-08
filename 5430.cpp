#include <iostream>
#include <deque>
#include <sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string command;
        string s;
        int n;
        cin >> command;
        cin >> n;
        cin >> s;

        deque<int> dq;
        if (s.length() != 2) {
            stringstream ss({s.begin()+1, s.end()-1});
            string line;
            while (getline(ss, line, ',')) dq.push_back(stoi(line));
        }
    
        bool isfront = true;
        bool flag = false;

        for (char c: command) {
            if (c == 'D') {
                if (!dq.empty()) {
                    if (isfront) dq.pop_front();
                    else dq.pop_back();
                }
                else {
                    cout << "error" << '\n';
                    flag = true;
                    break;
                }
            }
            else if (c == 'R') isfront = !isfront;
        }
        if (!flag) {
            if (isfront) {
                cout << '[';
                while (!dq.empty()) {
                    cout << dq.front();
                    dq.pop_front();
                    if (!dq.empty()) cout << ',';
                }
                cout << ']' << '\n';
            }
            else {
                cout << '[';
                while (!dq.empty()) {
                    cout << dq.back();
                    dq.pop_back();
                    if (!dq.empty()) cout << ',';
                }
                cout << ']' << '\n';
            }
        }
    }
}