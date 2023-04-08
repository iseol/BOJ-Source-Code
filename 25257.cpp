#include <iostream>
using namespace std;

int main() {
    cout.precision(15);
    cout << fixed;

    double d, s, e;
    cin >> d >> s >> e;
    cout << ((d-s)/(d*(d-s-e)) * min(s, d-s-e)) + (1/d) * (s-min(s, d-s-e));
}