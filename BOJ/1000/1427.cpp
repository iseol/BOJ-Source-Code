#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> arr;
    for (char c : s) arr.push_back(c-'0');
    sort(arr.begin(), arr.end(), [&](int a, int b) {return a > b;});
    for (int i : arr) cout << i;
}