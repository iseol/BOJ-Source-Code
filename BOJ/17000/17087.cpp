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
	
	int s, n; // 수빈이의 위치, 총 동생의 인원수 
	int a; // 동생의 위치 
	cin >> n >> s;
	cin >> a;
	int d = abs(s - a);
	
	for (int i = 1; i < n; i++) {
		s = a; // 동생을 찾음 
		cin >> a; // 다른 동생의 위치 입력
		
		d = gcd(d, abs(s - a)); // 거리와 기존 d의 최대공배수 
	}
	cout << d << '\n'; 
}
