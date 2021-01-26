#include <cstdio>
using namespace std;

int d[1001];

int main(void) {
	int n;
	scanf("%d", &n);
	
	d[0] = 1;
	d[1] = 1;
	for (int i = 1; i <= n; i++)
		d[i] = (d[i-1] + 2*d[i-2]) % 10007;
	printf("%d\n", d[n]);
	return 0;
}
