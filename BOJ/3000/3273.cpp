#include <iostream>
using namespace std;

int seq[1000001] = {};
bool occur[2000001];


int main() {
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> seq[i];
	cin >> x;
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (x-seq[i] > 0 && occur[x-seq[i]]) ans++;
		occur[seq[i]] = true;
	}

	cout << ans << '\n';
}

