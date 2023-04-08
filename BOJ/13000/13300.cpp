#include <iostream>
using namespace std;

int students[2][7];

int main() {
	int n, k;
	cin >> n >> k;
	
	int temp, grade;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp) {
			cin >> grade;
			students[1][grade]++;
		}
		else {
			cin >> grade;
			students[0][grade]++;
		}
	}
	
	int ans = 0;
	for (int c = 0; c <= 1; c++) {
		for (int i = 1; i <= 6; i++) {
			if ((students[c][i] % k) == 0) ans += students[c][i] / k;
			else ans += (students[c][i] / k) + 1;
		}
	}
	
	cout << ans << '\n';
}
