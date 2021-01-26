#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string bin;
	cin >> bin;
	int x = bin.size();
	if (x % 3 == 1) cout << bin[0];
	else if (x % 3 == 2) cout << (bin[0]-'0')*2 + (bin[1]-'0');
	
	for (int i = x % 3; i < x; i += 3)
		cout << (bin[i]-'0')*4 + (bin[i+1]-'0')*2 + (bin[i+2]-'0');
	cout << '\n';
}
