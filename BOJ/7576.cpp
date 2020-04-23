#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int box[1001][1001];
int check[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool checkRange(int x, int y) {
	if (x < 0 || x >= N || y<0 || y>M) {
		return false;
	}
	return true;
}
void bfs() {
	queue<pair<int,int> > q;
	int day = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 1) {
				q.push(make_pair(i,j));
			}
		}
	}
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		day = box[x][y] + 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (checkRange(nx, ny) && box[nx][ny] == 0) {
				box[nx][ny] = day;
				q.push(make_pair(nx, ny));
				
			}
		}
	}
}
int main() {
	int ans = -2;
	cin >> M >> N;
	bool all = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 0)
				all = false;
		}
	}
	if (all) ans = 0;
	else bfs();
	bool flag = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) {
				flag = false;
				break;
			}
			else {
				ans = max(ans, box[i][j]);
			}
		}
		if (!flag) break;
	}
	if (!flag) cout << "-1" << '\n';
	else cout << ans-1 << '\n';
	return 0;
}