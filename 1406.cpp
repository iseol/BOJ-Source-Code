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
		if (command == 'P') {	
			cin >> temp;
			lst.insert(cursor, temp); // �̰� ���ص� ��(?) 
		}
		else if (command == 'B') {
			if (cursor != lst.begin()) {
				cursor--;
				cursor = lst.erase(cursor); // �̰� �ٽ� �־������ 
			}
		}
		else if (command == 'D') {
			if (cursor != lst.end()) {
				cursor++;
			}
		}
		else if (command == 'L') {
			if (cursor != lst.begin()) {
				cursor--;
			}
		}
	}
	
	for (char c: lst)
		cout << c;
}
