#include <iostream>
using namespace std;

int A[1001], d[1001];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	fill(d, d+N+1, 1);
	
	for (int i = 1; i <= N; i++) {
		for (int j = i-1; j >= 1; j--) if (A[i] > A[j]) d[i] = max(d[i], d[j]+1);
	}
	
	int MAX = -1;
	for (auto i : d) MAX = max(MAX, i);
		
	cout << MAX;
}