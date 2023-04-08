#include <iostream>
#include <string>
#include <cmath> 
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	 
	string str;
	int b;
	cin >> str >> b;
	
	int k = str.size() - 1; // Áö¼ö 
	
	int ans = 0;
	int sz = str.size();
	for (int i = 0; i < sz; i++) {
		ans += (str[i] < 'A' ? str[i]-'0' : str[i]-55) * pow(b, k);
		k--;
	}
		
	cout << ans << '\n';
}
