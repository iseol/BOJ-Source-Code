#include <iostream>
using namespace std;

int freq[201]; // -100 -> 0(idx), 0 -> 100(idx), 100 -> 200(idx)

int main() {
	int n, v;
	cin >> n;
	
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		freq[temp+100]++;
	}
	
	cin >> v;
	cout << freq[v+100] << '\n';
}
