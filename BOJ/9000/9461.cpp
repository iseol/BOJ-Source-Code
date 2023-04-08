#include <iostream>
using namespace std;

typedef long long ll;
ll d[101] = {0, 1, 1, 1, 2, 2};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for (int i = 6; i <= 100; i++) d[i] = d[i-1] + d[i-5];

	int tc;
	cin >> tc;
	
	while (tc--) {
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}
}
