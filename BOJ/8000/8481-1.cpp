#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream dres;
    
    dres.open("1resres.txt");

    int val = 2932;
    for (int i = 0; i < 10000; i++) {
        val = val-(2*i) >= 0 ? val-(2*i) : 2932;
        dres << val  << '\n';
    }
}