#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string str;
	getline(cin, str);
	
	int words = 0;
	if (str[0] == ' ') words--;
	if (str.back() == ' ') words--;
	
	int x = str.size();
	for (int i = 0; i < x; i++) {
		if (str[i] == ' ') words++;
	}
	
	cout << words + 1 << '\n';
}
