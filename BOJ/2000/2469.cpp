#include <iostream>
using namespace std;

char map[1000][25];
char top[26], bot[26];
char q[25];
int k, n;
int q_line;
bool flag = true;

int main(void) {
	cin >> k;
	cin >> n;
	for (int i = 0; i < k; i++) {
		top[i] = 'A'+i;
		cin >> bot[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k-1; j++) {
			cin >> map[i][j];
			if (map[i][j] == '?')
				q_line = i;
		}
	}
	char temp;
	for (int i = 0; i < q_line; i++) {
		for (int j = 0; j < k-1; j++) {
			if (map[i][j] == '-') {
				temp = top[j+1];
				top[j+1] = top[j];
				top[j] = temp;
			}
		}
	}
	for (int i = n; i > q_line; i--) {
		for (int j = 0; j < k-1; j++) {
			if (map[i][j] == '-') {
				temp = bot[j+1];
				bot[j+1] = bot[j];
				bot[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < k-1; i++) {
		if (top[i] == bot[i])
			q[i] = '*';
		else if (top[i] == bot[i+1] && top[i+1] == bot[i]) {
			q[i] = '-';
			temp = top[i+1];
			top[i+1] = top[i];
			top[i] = temp;
		}
		else {
			flag = false;
			break;
		}
	}
	
	if (flag) {
		for (int i = 0; i < k-1; i++) {
			cout << q[i];
		}
	}
	else {
		for (int i = 0; i < k-1; i++) {
			cout << 'x';
		}
	}
}

