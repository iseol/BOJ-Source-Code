#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

struct Monsterinfo {
	string name;
	
	int atk;
	int def;
	int mxhp;
	int hp;
	int exp;
};

struct Playerinfo {
	int atk;
	int watk;
	
	int def;
	int adef;
	
	int mxhp;
	int hp;
	
	int lvl;
	int exp;
	
	bool ishr;
	bool isre;
	bool isco;
	bool isex;
	bool isdx;
	bool ishu;
	bool iscu;
	
	int rings;
};

int n, m;
int turn = 0;
bool hasended = false;
char board[105][105];
struct Monsterinfo monsters[101][101];
pair<char, string> items[101][101]; // abilities are also in string type..


struct Playerinfo player = {2, 0, 2, 0, 20, 20, 1, 0, false, false, false, false, false, false, false, 0};
pair<int, int> cur, startpos;

bool OOB(int a, int b) {
	return (a <= 0 || a > n || b <= 0 || b > m);
}

void re() {
	player.hp = player.mxhp;
	cur = startpos;
	player.isre = false;
	player.rings--;				
}

void res(bool dead, bool clear, string offender) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == cur.first && j == cur.second && !dead) cout << '@';
			else cout << board[i][j];
		}
		cout << '\n';
	}
	cout << "Passed Turns : " << turn << '\n';
	cout << "LV : " << player.lvl << '\n';
	cout << "HP : " << player.hp << '/' << player.mxhp << '\n';
	cout << "ATT : " << player.atk << '+' << player.watk << '\n';
	cout << "DEF : " << player.def << '+' << player.adef << '\n';
	cout << "EXP : " << player.exp << '/' << 5*player.lvl << '\n';
	
	if (clear) cout << "YOU WIN!";
	else if (dead) cout << "YOU HAVE BEEN KILLED BY " << offender << "..";
	else cout << "Press any key to continue.";
	hasended = true;
}

void getxp(int x, int y) {
	
	int xp;
	if (player.isex) xp = monsters[x][y].exp * 1.2;
	else xp = monsters[x][y].exp;
	
	if (5*player.lvl > player.exp + xp) {
		player.exp += xp;
	}
	else { // lvl up
		do {
			player.lvl++;
			
			player.mxhp += 5;
			player.atk += 2;
			player.def += 2;
			player.hp = player.mxhp;
			
			xp -= (5*player.lvl - player.exp);
			player.exp = 0;
		} while (5*player.lvl <= xp);
	}
}

void fight(int x, int y) {
	if (board[x][y] == 'M' && player.ishu) player.hp = player.mxhp;
	int idx = 1;
	while (1) {
		// player's attack
		if (idx == 1) {
			if (player.isco && player.isdx) monsters[x][y].hp -= max(1, 3*(player.atk + player.watk) - monsters[x][y].def);
			else if (player.isco) monsters[x][y].hp -= max(1, 2*(player.atk + player.watk) - monsters[x][y].def);
			else monsters[x][y].hp -= max(1, (player.atk + player.watk) - monsters[x][y].def);
		}
		else {
			monsters[x][y].hp -= max(1, (player.atk + player.watk) - monsters[x][y].def);
		}
		if (monsters[x][y].hp <= 0) {
			if (player.ishr) {
				player.hp += 3;
				if (player.hp > player.mxhp) player.hp = player.mxhp;
			}
			getxp(x, y);
			cur = {x, y};
			if (board[x][y] == 'M') res(false, true, monsters[x][y].name);
			board[x][y] = '.';
			return;
		}
		
		// monster's attack
		if (idx == 1 && board[x][y] == 'M' && player.ishu) player.hp -= 0;
		else player.hp -= max(1, monsters[x][y].atk - (player.def + player.adef));
		
		if (player.hp <= 0) {
			if (player.isre) {
				re();
				monsters[x][y].hp = monsters[x][y].mxhp;
			}
			else {
				player.hp = 0;
				res(true, false, monsters[x][y].name);
			}
			return;
		}
		
		idx++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// inputs...
	int k = 0;
	int l = 0;
	
	cin >> n >> m;
	
	string temp;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		int stridx = 1;
		for (char c: temp) {
			board[i][stridx] = c;
			stridx++;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == '&' || board[i][j] == 'M') k++;
			if (board[i][j] == 'B') l++;
			if (board[i][j] == '@')  {
				cur = {i, j};
				startpos = cur;
				board[i][j] = '.';
			}
		}
	}
	
	string command;
	cin >> command;
	int len = command.length();
	
	while (k--) {
		int x, y;
		cin >> x >> y;
		cin >> monsters[x][y].name;
		cin >> monsters[x][y].atk >> monsters[x][y].def >> monsters[x][y].mxhp >> monsters[x][y].exp;
		
		monsters[x][y].hp = monsters[x][y].mxhp;
	}
	
	while (l--) {
		int x, y;
		cin >> x >> y;
		cin >> items[x][y].first >> items[x][y].second;
	}
	
	for (char c: command) {
		turn++;
		int nx = cur.first;
		int ny = cur.second;
		switch (c) {
			case 'R':
				ny++;
				break;
			case 'D':
				nx++;
				break;
			case 'L':
				ny--;
				break;
			case 'U':
				nx--;
				break;
		}
		if (OOB(nx, ny)) {
			if (board[cur.first][cur.second] == '^') {
				if (player.isdx) player.hp -= 1;
				else player.hp -= 5;
				if (player.hp <= 0) {
					if (player.isre) re();
					else {
						player.hp = 0;
						res(true, false, "SPIKE TRAP");
					}
				}
			}
		}
		switch (board[nx][ny]) {
			case '#': {
				if (board[cur.first][cur.second] == '^') {
					if (player.isdx) player.hp -= 1;
					else player.hp -= 5;
					if (player.hp <= 0) {
						if (player.isre) re();
						else {
							player.hp = 0;
							res(true, false, "SPIKE TRAP");
						}
					}
				}
				break;
			}
			case '&': {
				fight(nx, ny);
				break;
			}
			case 'M': {
				fight(nx, ny);
				break;
			}
			case '^': {
				cur = {nx, ny};
				if (player.isdx) player.hp -= 1;
				else player.hp -= 5;
				if (player.hp <= 0) {
					if (player.isre) re();
					else {
						player.hp = 0;
						res(true, false, "SPIKE TRAP");
					}
				}
				break;
			}
			case 'B': {
				board[nx][ny] = '.';
				switch (items[nx][ny].first) {
					case 'W': {
						player.watk = stoi(items[nx][ny].second);
						break;
					}
					case 'A': {
						player.adef = stoi(items[nx][ny].second);
						break;
					}
					case 'O': {
						if (player.rings < 4) {
							if (items[nx][ny].second == "HR" && !player.ishr) {
								player.ishr = true;
								player.rings++;
							}
							if (items[nx][ny].second == "RE" && !player.isre) {
								player.isre = true;
								player.rings++;
							}
							if (items[nx][ny].second == "CO" && !player.isco) {
								player.isco = true;
								player.rings++;
							}
							if (items[nx][ny].second == "EX" && !player.isex) {
								player.isex = true;
								player.rings++;
							}
							if (items[nx][ny].second == "DX" && !player.isdx) {
								player.isdx = true;
								player.rings++;
							}
							if (items[nx][ny].second == "HU" && !player.ishu) {
								player.ishu = true;
								player.rings++;
							}
							if (items[nx][ny].second == "CU" && !player.iscu) {
								player.iscu = true;
								player.rings++;
							}
						}
						break;
					}
				}
				
				cur = {nx, ny};
				break;
			}
			case '.': {
				cur = {nx, ny};
				break;
			}
		}
		
		if (hasended) return 0;
	}
	res(false, false, "fdsfafsaf");
}
