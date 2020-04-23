#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
int N, K, L;
int board[101][101] = { 0, };
deque<pair<int, int> > snake;
int dir = 0;
//동 남 서 북
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int time[10001] = { 0, };
char d[10001];
bool checkGameOver(int x, int y) {
	if (board[x][y] == 1)
		return true;
	if (x < 0 || x >= N || y < 0 || y >= N)
		return true;
	return false;
}

int Dummy() {
	int s = 0;
	while (true) {
		//방향 정보 존재하는 경우
		if (time[s] == 1) {
			if (d[s] == 'L')
				dir = (dir + 3) % 4;
			else if (d[s] == 'D')
				dir = (dir + 1) % 4;
		}
		int nextX = snake.back().first + dx[dir];
		int nextY = snake.back().second + dy[dir];

		if (checkGameOver(nextX, nextY)) {
			s++;
			return s;
		}
			
		snake.push_back(make_pair(nextX, nextY));
			
		//사과가 있는 경우
		if (board[nextX][nextY] == 2) {
			board[nextX][nextY] = 1;
		}
		else {
			board[nextX][nextY] = 1;
			board[snake.front().first][snake.front().second] = 0;
			snake.pop_front();

		}

		s++;
		
	}
	
}
int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		board[x-1][y-1] = 2;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int second;
		char direction;
		cin >> second >> direction;
		time[second] = 1;
		d[second] = direction;
	}

	board[0][0] = 1;
	snake.push_back(make_pair(0, 0));
	
	cout << Dummy() << '\n';
}