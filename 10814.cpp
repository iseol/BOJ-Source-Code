#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

tuple<int, int, string> arr[100000];
bool comp(const tuple<int, int, string>& a, const tuple<int, int, string>& b) {
	int aidx = get<0>(a);
	int bidx = get<0>(b);
	int aage = get<1>(a);
	int bage = get<1>(b);
	if (aage == bage) return aidx < bidx;
	else return aage < bage;

}
int main() {
	int n;
	cin >> n;
	
	int age;
	string name;
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		arr[i] = make_tuple(i, age, name);
	}
	sort(arr, arr+n, comp);
	
	for (int i = 0; i < n; i++) {
		cout << get<1>(arr[i]) << ' ' << get<2>(arr[i]) << '\n';
	}
}
