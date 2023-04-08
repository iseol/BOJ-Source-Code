#include <cstdio>
using namespace std;

int d[1001]= {1, 1};

int solve(int n) {
	if (d[n] > 0) return d[n];
	d[n] = (solve(n-1) + 2*solve(n-2)) % 10007;
	return d[n];
}

int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d\n", solve(n));
}
