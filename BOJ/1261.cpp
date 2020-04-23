#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <memory.h>
using namespace std;
int M,N;
int maze[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int min_crashed[101][101];
int visited[101][101] = { 0, };
int ans = 987654321;

bool checkRange(int x,int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) {
		return false;
	}
	return true;
}
void dfs(int x, int y, int cnt) {
	if (min_crashed[x][y] <= cnt) return;
	else min_crashed[x][y] = cnt;

	if (x == N-1 && y == M-1) {
		ans = min(ans, cnt);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (checkRange(nx,ny) && !visited[nx][ny]) {
			if (maze[nx][ny] == 0) {
				visited[nx][ny] = 1;
				dfs(nx, ny, cnt);
				visited[nx][ny] = 0;
			}
			else {
				visited[nx][ny] = 1;
				if (ans > cnt + 1) {
					dfs(nx, ny, cnt + 1);
				}
				visited[nx][ny] = 0;
			}
		}
	}
}
int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			maze[i][j] = str[j]-'0';
			min_crashed[i][j] = 987654321;
		}
	}
	visited[0][0] = 1;
	dfs(0, 0, 0);
	cout << ans << '\n';
	return 0;
}