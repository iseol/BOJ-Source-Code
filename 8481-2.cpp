#include <fstream>
using namespace std;

unsigned long long d[10001];

int main() {
    ofstream file;
    file.open("2.txt");
    d[1] = 1;
    d[2] = 1;
    for (int i = 3; i <= 10000; i++) {
        d[i] = (d[i-1] + d[i-2]) % 9099099909999099999LL;
    }
    for (int i = 1; i <= 10000; i++) {
        file << d[i] << ", ";
    }
    file << "0.";
}