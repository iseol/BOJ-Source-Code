#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int boardq[5][5]; // 00000000
char boardcol[5][5]; // wwwwww
int itemq[10][4][4];  // asdf
char itemcol[10][4][4]; // asdf

int stq[10][4][4]; // rotated items
char stcol[10][4][4];

void init() {
    for (int in = 0; in < 5; in++) fill(boardcol[in], boardcol[in]+5, 'W');
    for (int in = 0; in < 5; in++) fill(boardq[in], boardq[in]+5, 0);
}

void rotate(int dir, int item) {
    int tempq[4][4];
    char tempcol[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            stq[item][i][j] = itemq[item][i][j];
            stcol[item][i][j] = itemcol[item][i][j];
        }
    }
    while (dir--) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                tempq[i][j] = stq[item][4-j-1][i];
                tempcol[i][j] = stcol[item][4-j-1][i];
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                stq[item][i][j] = tempq[i][j];
                stcol[item][i][j] = tempcol[i][j];
            }
        }
    }
}

void paste(int loc, int item) {
    int offx, offy;
    if      (loc == 0) {offx = 0; offy = 0;}
    else if (loc == 1) {offx = 0; offy = 1;}
    else if (loc == 2) {offx = 1; offy = 0;}
    else if (loc == 3) {offx = 1; offy = 1;}

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            boardq[i+offx][j+offy] += stq[item][i][j];
            if (boardq[i+offx][j+offy] > 9) boardq[i+offx][j+offy] = 9;
            else if (boardq[i+offx][j+offy] < 0) boardq[i+offx][j+offy] = 0;
            if (stcol[item][i][j] == 'W') continue;
            boardcol[i+offx][j+offy] = stcol[item][i][j];
        }
    }
}

int check() {
    int r = 0;
    int b = 0;
    int g = 0; 
    int y = 0; 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            switch (boardcol[i][j]) {
                case 'R': {
                    r += boardq[i][j];
                    break;
                }
                case 'B': {
                    b += boardq[i][j];
                    break;
                }
                case 'G': {
                    g += boardq[i][j];
                    break;
                }
                case 'Y': {
                    y += boardq[i][j];
                    break;
                }
            }
        }
    }
    return 7*r + 5*b + 3*g + 2*y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int item = 0; item < n; item++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> itemq[item][i][j];
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> itemcol[item][i][j];
            }
        }
    }

    int mx = -987654321;
    vector<int> arr;
    for (int i = 0; i < 3; i++) arr.push_back(0);
    for (int i = 0; i < n-3; i++) arr.push_back(1);

    do {
        vector<int> sel;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) sel.push_back(i); 
        }
        do {
            for (int tmp = 0; tmp < 64; tmp++) {
                int brute = tmp;
                for (int i = 0; i < 3; i++) {
                    int dir = brute % 4;
                    brute /= 4;
                    
                    rotate(dir, sel[i]);
                }
                for (int tmp2 = 0; tmp2 < 64; tmp2++) {
                    int brute2 = tmp2;
                    init();
                    for (int i2 = 0; i2 < 3; i2++) {
                        int loc = brute2 % 4; // 0, 1, 2, 3
                        brute2 /= 4;
                        paste(loc, sel[i2]);
                    }
                    mx = max(mx, check());
                }
            }
        } while (next_permutation(sel.begin(), sel.end()));
    } while (next_permutation(arr.begin(), arr.end()));
    cout << mx;
}