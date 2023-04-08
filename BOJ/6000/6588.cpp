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
			prime[pn++] = i; // �ε��� 0���� ���� ����� 
			for (int j = i+i; j <= MAX; j += i) // i�� ��� ��� ���� 
				check[j] = true;
		}
	}
	
	int n = 0;
	while (true) { 
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i < pn; i++) { // prime[0]�� �ִ� 2�� Ȧ�� �Ҽ��� �ƴϱ� ������ 1���� 
			if (!check[n - prime[i]]) {
				cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
				break;
			}
		}
	}
}
