#include <iostream>
#include <algorithm>

using namespace std;

int N, Q;
int arr[100];

int main(void) {
	int N, Q;
	cin >> N >> Q;
	
	cin >> arr[0];
	for (int i = 1; i < N; i++) {
		cin >> arr[i];
		arr[i] += arr[i-1];
	}
	int sec;
	for (int i = 0; i < Q; i++) {
		cin >> sec;
		cout << lower_bound(arr, arr+N, sec+1)-arr+1 << '\n';
	}
}
