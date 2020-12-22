#include <iostream>
#include <vector>

using namespace std;

int a, b, t;
vector<int> a_vec;
vector<int> b_vec;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		a_vec.push_back(a);
		b_vec.push_back(b);
	}
	for (int i = 0; i < t; i++) {
		cout << a_vec[i]+b_vec[i] << '\n';
	}	
}
