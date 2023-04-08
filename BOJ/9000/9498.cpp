#include <iostream>

using namespace std;

int score;

int main(void) {
	char grade[6] = {'D', 'C', 'B', 'A', 'A'};
	
	cin >> score;
	
	if (score < 60) {
		cout << 'F';
	} else {
		cout << grade[(score - 60) / 10];
	}
}
