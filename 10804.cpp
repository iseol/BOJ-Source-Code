#include <iostream>
#include <algorithm>
using namespace std;

int arr[20];

int main() {
	for (int i = 0; i < 20; i++) arr[i] = i+1;
	
	int start, end;
	for (int t = 0; t < 10; t++) {
		cin >> start >> end;
		reverse(arr+start-1, arr+end);
	}
	
	for (int i = 0; i < 20; i++) cout << arr[i] << ' ';
}
