#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	string quiz;
	int plus_score = 1; // 문제의 점수 
	int score = 0;
	while (t--) {
		cin >> quiz;
		for (char ox: quiz) {
			if (ox == 'O') {
				score += plus_score;
				plus_score++;
			}
			else {
				plus_score = 1;
			}
		}
		cout << score << '\n';
		plus_score = 1;
		score = 0;
	}
	return 0;
}
