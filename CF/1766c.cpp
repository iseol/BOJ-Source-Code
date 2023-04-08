#include <iostream>
#include <vector>
using namespace std;

int arr[2][200005];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int m;
        cin >> m;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < m; j++) {
                char tmp;
                cin >> tmp;
                
                if (tmp == 'B') arr[i][j] = 1;
                else arr[i][j] = 0;
            }
        }

        vector<int> v;
        for (int i = 0; i < m; i++) {
            int tmp;
            if (arr[0][i] + arr[1][i] == 2) tmp = 2;
            else if (arr[0][i]) tmp = 0;
            else if (arr[1][i]) tmp = 1;

            if (tmp == 2 && v.size() == 0) continue;
            v.push_back(tmp);
        }

        if (v.size() == 0) {
            cout << "YES\n";
            continue;
        }

        int cnt = 0, s = v[0];
        bool flag = true;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] == 2) {
                cnt++;
                continue;
            }

            else if ((s == v[i] && cnt % 2 == 1) || (s != v[i] && cnt % 2 == 0)) flag = false;
            cnt = 0;
            s = v[i];
        }

        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}