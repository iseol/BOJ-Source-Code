#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		list<char> lst;
		list<char>::iterator cursor = lst.begin();
		
		for (char c: s) {
			switch (c) {
				case '<':
					if (cursor != lst.begin()) cursor--;
					break;
				case '>':
					if (cursor != lst.end()) cursor++;
					break;
				case '-':
					if (cursor != lst.begin()) {
						cursor--;
						cursor = lst.erase(cursor);
					}
					break;
				default:
					lst.insert(cursor, c);
					break;
			}
		}
		for (char c: lst) cout << c;
		cout << '\n';
	}
}
