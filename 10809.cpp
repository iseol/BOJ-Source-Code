#include <iostream>
#include <string>
using namespace std;

int cnt[123];

int main(void) {
	for (int i = 'a'; i <= 'z'; i++)
		cnt[i] = -1;
	
	string word;
	cin >> word;
	
	int x = word.size();
	for (int i = 0; i < x; i++)
		if (cnt[word[i]] == -1)
			cnt[word[i]] = i;
		
	for (int i = 'a'; i <= 'z'; i++)
		cout << cnt[i] << ' ';
	cout << '\n';
	return 0;
}
