#include <iostream>
#include <deque>
#include <algorithm>
#define EXCEPTION 0.15 
using namespace std;

double n, sum;
int temp, del;
deque<int> dq;
int main(void) {
	cin >> n;
	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		dq.push_back(temp);
	}
	sort(dq.begin(), dq.end());
	del = static_cast<int>(n * EXCEPTION + .5);
	for (int i = 0; i < del; i++)
		dq.pop_front();
	for (int i = 0; i < del; i++)
		dq.pop_back();
	n -= del*2; // 전체 개수 
	for (long unsigned int i = 0; i < dq.size(); i++)
		sum += dq[i];
	cout << static_cast<int>((sum / n) + .5) << endl;
}

