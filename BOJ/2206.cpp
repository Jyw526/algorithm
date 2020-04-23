#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <memory.h>
using namespace std;
int N, M;
int map[1001][1001];
const int MAX = 987654321;
bool visited[1001][1001][2];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int ans = MAX;

bool checkRange(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) {
		return false;
	}
	return true;
}

int bfs() {
	//(x,y)(cnt,wall부셨는지)
	queue < pair<pair<int, int>, pair<int, int> > > q;
	q.push(make_pair(make_pair(0, 0), make_pair(1, 0)));
	visited[0][0][0] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second.first;
		int wall = q.front().second.second;
		q.pop();

		if (x == N - 1 && y == M - 1) {
			return cnt;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (checkRange(nx, ny)) {
				if (map[nx][ny] == 0 && !visited[nx][ny][wall]) {
					visited[nx][ny][wall] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, wall)));
				}
				else if(map[nx][ny] == 1 && wall == 0){
					visited[nx][ny][wall+1] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, 1)));
				}
			}
		}
	}
	return -1;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			map[i][j] = str[j] - '0';
		}
	}
	cout << bfs() << '\n';
	return 0;
}