#include <iostream>
#include <string>
#include <list>

using namespace std;

string s;
char command, temp;
int n;

int main(void) {
	cin >> s;
	
	list<char> lst(s.begin(), s.end());
	list<char>::iterator cursor = lst.end();
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> command;
		switch (command) {
			case 'P':
				cin >> temp;
				lst.insert(cursor, temp);
				break;
			case 'B':
				if (cursor != lst.begin()) {
					cursor--;
					cursor = lst.erase(cursor);
				}
				break;
			case 'D':
				if (cursor != lst.end()) {
					cursor++;
				}
				break;
			case 'L':
				if (cursor != lst.begin()) {
					cursor--;
				}
				break;
		}
	}
	
	for (char c: lst)
		cout << c;
}
