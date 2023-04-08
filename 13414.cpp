#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, l;
    cin >> k >> l;
    
    unordered_map<string, int> m;
    string temp;
    for (int i = 0; i < l; i++) {
        cin >> temp;
        if (m.find(temp) == m.end()) m[temp] = i;
        else {
            m.erase(temp);
            m[temp] = i;
        }
    }


    vector<pair<string,int> > slist(m.begin(), m.end());
    sort(slist.begin(), slist.end(), [&](auto a, auto b) { return a.second < b.second; });

    int en = min(k, (int)slist.size());

    for (int i = 0; i < en; i++) cout << slist[i].first << '\n';
}