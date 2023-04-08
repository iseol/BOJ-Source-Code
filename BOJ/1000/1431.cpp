#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string sireal_no[1000];
int n;

int GetSum(string a) {
	int length = a.length();
	int sum = 0;
	
	for (int i = 0; i < length; i++) {
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0) { // 숫자인 경우 
			sum += a[i] - '0';
		}
	}
	return sum;
}
bool compare(string a, string b) {
	if (a.length() < b.length()) {
		return 1;
	} else if (a.length() > b.length()) {
		return 0;
	}
	
	// 길이가 같은 경우라면
	else {
		int a_sum = GetSum(a);
		int b_sum = GetSum(b);
		
		if (a_sum != b_sum) {
			return a_sum < b_sum;
		}
		else {
			return a < b;
		}
	} 
 
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> sireal_no[i];
	}
	sort(sireal_no, sireal_no+n, compare);
	
	for (int i = 0; i < n; i++) {
		if (i > 0 && sireal_no[i] == sireal_no[i-1]) {
			continue;
		} else {
			cout << sireal_no[i] << '\n';
		}
	}
}
