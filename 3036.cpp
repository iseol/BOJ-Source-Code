#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int fc;
    cin >> fc; 
    for (int i = 0; i < n-1; i++) {
        int c;
        cin >> c;
        
        cout << fc / gcd(fc, c) << '/' << c / gcd(fc, c) << '\n';
    }
}