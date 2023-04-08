#include <iostream>
#include <vector>
using namespace std;

int cnt[5], id[5];
int info[6];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    for (int i = 0; i < 6; i++) {
        int dir, l;
        cin >> dir >> l;
        info[i] = l;

        id[dir] = i;
        cnt[dir]++;
    }

    vector<int> idx;
    for (int i = 1; i <= 4; i++) {
        if (cnt[i] == 1) idx.push_back(id[i]);
    }

    cout << k * ((info[idx[0]] * info[idx[1]]) - (info[(idx[0]+3)%6] * info[(idx[1]+3)%6]));
}