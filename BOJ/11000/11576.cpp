#include <iostream>
#include <stack>
#include <cmath> 
using namespace std;

stack<int> ans;
int decimal;

int main(void) {
	int a, b;
	cin >> a >> b;
	int k; // ����
	cin >> k;
	int x; // A������ �� �ڸ��� 
	while (k--) {
		cin >> x;
		decimal += x * pow(a, k);
	}
	while (true) {
		if (decimal == 0) break;
		ans.push(decimal%b);
		decimal /= b;
	}
	while (!ans.empty()) {
		cout << ans.top() << ' ';
		ans.pop();
	}
	cout << '\n';
}
