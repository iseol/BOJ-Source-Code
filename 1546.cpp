#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	
	vector<double> grades(n);
	double x;
	double MAX = -1;
	for (int i = 0; i < n; i++) {
		cin >> x;
		grades.push_back(x);
		if (MAX < x) MAX = x;
	}
	double ans = 0;
	for (double score: grades)
		ans += (score / MAX) * 100;
	
	ans = ans / static_cast<double>(n);
	cout.precision(15);
	cout << ans << '\n';
	return 0;
}
