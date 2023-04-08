#include <iostream>
using namespace std;

char s[1001];

int main() {
    cin >> s;
    
    if (s[0] >= 'a') cout << (char)(s[0]-32);
    else cout << s[0];
    for (int i = 1; s[i] != '\0'; i++) cout << s[i]; 
}