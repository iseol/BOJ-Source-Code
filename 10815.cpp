#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int temp;
int arr[500000];

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+n);
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &temp);
		
		printf("%d ", binary_search(arr, arr+n, temp));
	}
}
