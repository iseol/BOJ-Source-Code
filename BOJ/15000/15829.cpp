#include <iostream>
using namespace std;

int arr[51];

int main() {
    int l;
    cin >> l;
    
    string s;
    cin >> s;

    for (int i = 0; i < l; i++) arr[i] = s[i]-'a'+1;

    long long h = 0;
    for (int i = 0; i < l; i++) {
        long long temp = arr[i] % 1234567891;
        for (int j = 0; j < i; j++) {
            temp *= 31;
            temp %= 1234567891;
        }
        h += temp;
        h %= 1234567891;
    }

    cout << h;
}