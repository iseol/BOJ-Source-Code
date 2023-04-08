#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;

        vector<int> freq(n+1);
        
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }
        

        sort(freq.begin(), freq.end(), [] (int a, int b) {return a > b;});

        int ans = freq[0];
        int last = freq[0];
        for (int i = 1; i <= n; i++) {
            if (last == 0) break;
            
            if (freq[i] >= last) {
                ans += last - 1;
                last--;
            }
            else {
                ans += freq[i];
                last = freq[i];
            }
        }
        cout << ans << '\n';
        
    }
}