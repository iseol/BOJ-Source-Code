#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	int r = a % b;
	return gcd(b, r);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int s, n; // �������� ��ġ, �� ������ �ο��� 
	int a; // ������ ��ġ 
	cin >> n >> s;
	cin >> a;
	int d = abs(s - a);
	
	for (int i = 1; i < n; i++) {
		s = a; // ������ ã�� 
		cin >> a; // �ٸ� ������ ��ġ �Է�
		
		d = gcd(d, abs(s - a)); // �Ÿ��� ���� d�� �ִ����� 
	}
	cout << d << '\n'; 
}
