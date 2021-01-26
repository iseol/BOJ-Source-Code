#include <iostream>
#include <string>
using namespace std;

int cnt[58]; // cnt[48] ~ cnt[57]

int main(void) {
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	
	string strabc = to_string(a*b*c);
	for (char num: strabc)
		cnt[num]++;
		
	for (int i = '0'; i <= '9'; i++)
		cout << cnt[i] << '\n';
		
	return 0;
}
