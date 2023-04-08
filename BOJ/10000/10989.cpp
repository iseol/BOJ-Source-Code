#include <iostream>

using namespace std;

int arr[10001];
int n;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[x]++;
	}
	for (int i = 0; i < 10001; i++) {
		while (arr[i] != 0) {
			cout << i << '\n';
			arr[i]--;
		}
	}
}
