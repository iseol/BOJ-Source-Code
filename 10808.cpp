#include <iostream>
using namespace std;

int arr[123]; // idx : 97 ~ 122

int main() {
	string s;
	cin >> s;
	
	for (char c: s) arr[c]++;
	
	for (int i = 97; i <= 122; i++) cout << arr[i] << ' ';
}
