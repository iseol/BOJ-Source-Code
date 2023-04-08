#include <iostream>
#include <queue>
#include <deque>
#define X first
#define Y second
using namespace std;

int board[101][101]; // 0 : empty, 1 : snake, 2 : apple  &  1 based

int main() {
    int n, k;
    cin >> n;
    
    cin >> k;
    while (k--) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 2;
    }

    int l;
    cin >> l;
    queue<pair<int, char>> change;
    while (l--) {
        int temp;
        char temp2;
        cin >> temp >> temp2;
        change.push({temp, temp2});
    }

    int x = 0;
    deque<pair<int, int>> snake;
    board[1][1] = 1;
    snake.push_back({1, 1});
    int dir = 2; // 1 up 2 right 3 down 4 left
    while (true) {
        x++;
        pair<int, int> nxt;
        switch (dir) {
            case 1: {
                nxt = {snake.front().X-1, snake.front().Y};
                break;
            }
            case 2: {
                nxt = {snake.front().X, snake.front().Y+1};
                break;
            }
            case 3: {
                nxt = {snake.front().X+1, snake.front().Y};
                break;
            }
            case 4: {
                nxt = {snake.front().X, snake.front().Y-1};
                break;
            }
        }
        if (nxt.X <= 0 || nxt.X > n || nxt.Y <= 0 || nxt.Y > n) { // wall
            cout << x;
            return 0;
        }
        else if (board[nxt.X][nxt.Y] == 1) { // snake collides with himself
            cout << x;
            return 0;
        }

        if (board[nxt.X][nxt.Y] == 2) { // snake eats an apple
            snake.push_front(nxt);
            board[nxt.X][nxt.Y] = 1;
        }
        else { // snake moves
            snake.push_front(nxt);
            board[nxt.X][nxt.Y] = 1;
            board[snake.back().X][snake.back().Y] = 0;
            snake.pop_back();
        }
        
        // changes direction
        if (x == change.front().X) {
            if (change.front().Y == 'D') {
                if (dir == 4) dir = 1;
                else dir++;
            }
            else {
                if (dir == 1) dir = 4;
                else dir--;
            }
            change.pop();
        }

        
    }
}