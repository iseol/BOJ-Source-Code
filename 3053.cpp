#include <iostream>
using namespace std;

const double pi = 3.14159265358979;

int main() {
    int r;
    cin >> r;

    double r1 = r * r * pi;
    double r2 = 2*r*r;

    cout.precision(6);
    cout << fixed;
    cout << r1 << '\n' << r2;
}