#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	
	int d[1001] = {0};
	vector<int> p(n+1);
	
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			d[i] = max(d[i], d[i-j] + p[j]);
	
	cout << d[n] << '\n';
	
}
