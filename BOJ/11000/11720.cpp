#include <cstdio>

int n, ans;
char arr[101];

int main(void) {
	scanf("%d", &n);
	
	scanf("%s", &arr);
	
	for (int i = 0; arr[i] != '\0'; i++) {
		ans += arr[i] - '0';
	}
	printf("%d", ans);
}
