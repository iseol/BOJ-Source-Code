#include <iostream>
#include <string>
using namespace std;

long long concat(int i, int j) {return stoi(to_string(i)+to_string(j));}

int main() {
    int i, j;
    cin >> i >> j;
    cout << concat(i, j);
}