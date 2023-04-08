#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[500005], b[500005];
vector<int> ans;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int na, nb;
    cin >> na >> nb;
    for (int i = 0; i < na; i++) cin >> a[i];
    for (int i = 0; i < nb; i++) cin >> b[i];
    sort(b, b+nb);
    
    for (int i = 0; i < na; i++) {
        if (!binary_search(b, b+nb, a[i])) ans.push_back(a[i]);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
}