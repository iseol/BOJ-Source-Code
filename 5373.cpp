#include <iostream>
#include <algorithm>
using namespace std;

char cube[6][3][3]; // top : 0, bottom : 1, front : 2, back : 3, left : 4, right : 5
char temp[3][3];
char temp2[6][3];
char col[6] = {'w', 'y', 'r', 'o', 'g', 'b'};

void reset() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cube[i][j][k] = col[i];
            }
        }
    }
}

void result() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << cube[0][i][j];
        }
        cout << '\n';
    }
}

void mid(int idx) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[i][j] = cube[idx][3-j-1][i];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[idx][i][j] = temp[i][j];
        }
    }
}

void up() {
    // top
    mid(0);
    // front -> left -> back -> right -> front
    for (int i = 0; i < 3; i++) temp2[4][i] = cube[2][0][i];
    for (int i = 0; i < 3; i++) temp2[3][i] = cube[4][0][i];
    for (int i = 0; i < 3; i++) temp2[5][i] = cube[3][0][i];
    for (int i = 0; i < 3; i++) temp2[2][i] = cube[5][0][i];

    for (int i = 0; i < 3; i++) cube[4][0][i] = temp2[4][i];
    for (int i = 0; i < 3; i++) cube[3][0][i] = temp2[3][i];
    for (int i = 0; i < 3; i++) cube[5][0][i] = temp2[5][i];
    for (int i = 0; i < 3; i++) cube[2][0][i] = temp2[2][i];
}

void down() {
    // bottom
    mid(1);
    // front -> right -> back -> left -> front
    for (int i = 0; i < 3; i++) temp2[5][i] = cube[2][2][i];
    for (int i = 0; i < 3; i++) temp2[3][i] = cube[5][2][i];
    for (int i = 0; i < 3; i++) temp2[4][i] = cube[3][2][i];
    for (int i = 0; i < 3; i++) temp2[2][i] = cube[4][2][i];

    for (int i = 0; i < 3; i++) cube[5][2][i] = temp2[5][i];
    for (int i = 0; i < 3; i++) cube[3][2][i] = temp2[3][i];
    for (int i = 0; i < 3; i++) cube[4][2][i] = temp2[4][i];
    for (int i = 0; i < 3; i++) cube[2][2][i] = temp2[2][i];
}

void front() {
    // front
    mid(2);
    // top -> right -> bottom -> left -> top
    for (int i = 0; i < 3; i++) temp2[5][i] = cube[0][2][i];
    for (int i = 0; i < 3; i++) temp2[1][i] = cube[5][2-i][0];
    for (int i = 0; i < 3; i++) temp2[4][i] = cube[1][0][i];
    for (int i = 0; i < 3; i++) temp2[0][i] = cube[4][2-i][2];

    for (int i = 0; i < 3; i++) cube[5][i][0] = temp2[5][i];
    for (int i = 0; i < 3; i++) cube[1][0][i] = temp2[1][i];
    for (int i = 0; i < 3; i++) cube[4][i][2] = temp2[4][i];
    for (int i = 0; i < 3; i++) cube[0][2][i] = temp2[0][i];
}

void back() {
    // back
    mid(3);
    // top -> left -> bottom -> right -> top
    for (int i = 0; i < 3; i++) temp2[4][i] = cube[0][0][i];
    for (int i = 0; i < 3; i++) temp2[1][i] = cube[4][i][0];
    for (int i = 0; i < 3; i++) temp2[5][2-i] = cube[1][2][i];
    for (int i = 0; i < 3; i++) temp2[0][i] = cube[5][i][2];

    for (int i = 0; i < 3; i++) cube[4][2-i][0] = temp2[4][i];
    for (int i = 0; i < 3; i++) cube[1][2][i] = temp2[1][i];
    for (int i = 0; i < 3; i++) cube[5][i][2] = temp2[5][i];
    for (int i = 0; i < 3; i++) cube[0][0][i] = temp2[0][i];
}

void left() {
    // left
    mid(4);
    // top -> front -> bottom -> back -> top
    for (int i = 0; i < 3; i++) temp2[2][i] = cube[0][i][0];
    for (int i = 0; i < 3; i++) temp2[1][i] = cube[2][i][0];
    for (int i = 0; i < 3; i++) temp2[3][2-i] = cube[1][i][0];
    for (int i = 0; i < 3; i++) temp2[0][i] = cube[3][2-i][2];
    
    for (int i = 0; i < 3; i++) cube[2][i][0] = temp2[2][i];
    for (int i = 0; i < 3; i++) cube[1][i][0] = temp2[1][i];
    for (int i = 0; i < 3; i++) cube[3][i][2] = temp2[3][i];
    for (int i = 0; i < 3; i++) cube[0][i][0] = temp2[0][i];
}

void right() {
    // right
    mid(5);
    // top -> back -> bottom -> front -> top
    for (int i = 0; i < 3; i++) temp2[3][i] = cube[0][2-i][2];
    for (int i = 0; i < 3; i++) temp2[1][2-i] = cube[3][i][0];
    for (int i = 0; i < 3; i++) temp2[2][i] = cube[1][i][2];
    for (int i = 0; i < 3; i++) temp2[0][i] = cube[2][i][2];

    for (int i = 0; i < 3; i++) cube[3][i][0] = temp2[3][i];
    for (int i = 0; i < 3; i++) cube[1][i][2] = temp2[1][i];
    for (int i = 0; i < 3; i++) cube[2][i][2] = temp2[2][i];
    for (int i = 0; i < 3; i++) cube[0][i][2] = temp2[0][i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        reset();

        string dir;
        while (n--) {
            cin >> dir;
            switch (dir[0]) {
                case 'U': {
                    if (dir[1] == '+') up();
                    else {up(); up(); up();}
                    break;
                }
                case 'D': {
                    if (dir[1] == '+') down();
                    else {down(); down(); down();}
                    break;
                }
                case 'F': {
                    if (dir[1] == '+') front();
                    else {front(); front(); front();}
                    break;
                }
                case 'B': {
                    if (dir[1] == '+') back();
                    else {back(); back(); back();}
                    break;
                }
                case 'L': {
                    if (dir[1] == '+') left();
                    else {left(); left(); left();}
                    break;
                }
                case 'R': {
                    if (dir[1] == '+') right();
                    else {right(); right(); right();}
                    break;
                }
            }
        }
        result(); // output
    }
}