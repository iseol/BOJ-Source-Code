#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> ans;
    int r = 0;
    for (char c : s) {
        if (c == '1') {
            r++;
        }
        else {
            ans.push_back(r);
            r = 0;
        }
    }
    ans.push_back(r);
    
    for (int d : ans) cout << d; 
}