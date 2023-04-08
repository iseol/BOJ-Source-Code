#include <iostream>
#define MAX 1000000
using namespace std;

int prime[MAX];
int pn;
bool check[MAX+1];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for (int i = 2; i <= MAX; i++) {
		if (check[i] == false) {
			prime[pn++] = i; // 인덱스 0부터 값이 담겨짐 
			for (int j = i+i; j <= MAX; j += i) // i의 배수 모두 삭제 
				check[j] = true;
		}
	}
	
	int n = 0;
	while (true) { 
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i < pn; i++) { // prime[0]에 있는 2는 홀수 소수가 아니기 때문에 1부터 
			if (!check[n - prime[i]]) {
				cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
				break;
			}
		}
	}
}
