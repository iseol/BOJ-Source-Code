#include <iostream>
#include <string>

using namespace std;

string str;

int main() {
	while (!cin.eof()) {
		getline(cin, str);
		cout << str << '\n';
	}
}
