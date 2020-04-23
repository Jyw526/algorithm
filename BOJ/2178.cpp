#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int map[101][101];
int d[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int visited[101][101];
queue<pair<int,int> > q;

bool checkRange(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) {
		return false;
	}
	return true;
}

void bfs() {
	q.push(make_pair(0, 0));
	visited[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + d[i][0];
			int ny = y + d[i][1];
			if (checkRange(nx, ny) && map[nx][ny] == 1 && visited[nx][ny] == 0) {
				visited[nx][ny] = visited[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
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
	bfs();
	cout << visited[N - 1][M - 1] << '\n';
	return 0;
}