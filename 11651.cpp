#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int n;
int temp1, temp2;
pair<int, int> arr[100000];

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp1 >> temp2;
		
		arr[i] = make_pair(temp1, temp2);
	}
	sort(arr, arr+n, comp);
	
	for (int i = 0; i < n; i++) {
		cout << arr[i].first << ' ';
		cout << arr[i].second << '\n';
	}
}
