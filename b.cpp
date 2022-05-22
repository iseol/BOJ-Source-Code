#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    double credit;
    string grade;

    double credits = 0;
    double res = 0;
    for (int i = 0; i < 20; i++) {
        cin >> s >> credit >> grade;
        if (grade == "P") continue;
        credits += credit;

        double score;
        if (grade == "A+") {
            score = 4.5;
        }
        else if (grade == "A0") {
            score = 4.0;
        }
        else if (grade == "B+") {
            score = 3.5;
        }
        else if (grade == "B0") {
            score = 3.0;
        }
        else if (grade == "C+") {
            score = 2.5;
        }
        else if (grade == "C0") {
            score = 2.0;
        }
        else if (grade == "D+") {
            score = 1.5;
        }
        else if (grade == "D0") {
            score = 1.0;
        }
        else score = 0.0;
        res += credit * score;
    }
    cout << res / credits;
}