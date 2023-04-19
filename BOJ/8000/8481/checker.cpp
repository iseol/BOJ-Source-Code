#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream p, m;
    p.open("gen1.out"), m.open("1.txt");

    string pp, mm;
    getline(p, pp), getline(m, mm);

    if (pp.length() != mm.length()) {
        cout << "Invalid Length!\n";
        return 0;
    }
    else {
        cout << "Valid Length!\n";
        
        int l = pp.length();
        for (int i = 0; i < l; i++) {
            if (pp[i] != mm[i]) {
                cout << "Invalid Result At " << i << "!\n";
                return 0;
            }
        }
    } 

    cout << "Valid Result\n";
}