#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cards;
int n, temp;
int m, find_card;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n;
	
	cards.reserve(500000);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		cards.push_back(temp);
	}
	if (cards.size() == 1) {
		
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> find_card;
			if (find_card == cards[0]) {
				cout << 1 << endl;
				return 0;
			}
		}
		cout << 0 << endl;
		return 0;
	}
	
	sort(cards.begin(), cards.end());
	
	cin >> m;
	
	int cnt[m];
	
	for (int i = 0; i < m; i++) {
		cin >> find_card;
		
		cnt[i] = upper_bound(cards.begin(), cards.end(), find_card) - lower_bound(cards.begin(), cards.end(), find_card);
	}
	
	for (int i = 0; i < m; i++) {
		cout << cnt[i] << ' ';
	}
}
