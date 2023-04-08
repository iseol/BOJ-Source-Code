#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    
    for (int i = 1; i <= 4500; i++) {
        x -= i;
        if (x <= 0) {
            if (i&1) { // odd
                cout << 1-x << '/' << i+x;
            }
            else {
                cout << i+x << '/' << 1-x;
            }
            break;
        }
    }
}