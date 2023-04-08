#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    unordered_set<int> us;
    for (int i = 0; i < a; i++) {
        int temp;
        cin >> temp;
        us.insert(temp);
    }

    int cnt = 0;
    for (int i = 0; i < b; i++) {
        int temp;
        cin >> temp;
        if (us.find(temp) != us.end()) cnt++;
    }

    cout << a+b-(2*cnt);
}