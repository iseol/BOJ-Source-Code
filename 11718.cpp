#include <iostream>
#include <cstring>

using namespace std;

string str;

int main() {
	while (1) {
		getline(cin, str);
		if (str == "") break;
		cout << str << '\n';
	}
}
