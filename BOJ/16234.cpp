#include <iostream>
#include <algorithm>
using namespace std;
int N, L, R;
int map[51][51];
int visited[51][51];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int total = 0;
int cnt = 0;
int ans = 0;
bool moved = false;

bool checkRange(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < N)
		return true;
	return false;
}
void dfs(int x,int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (checkRange(nx,ny) && visited[nx][ny]==-1) {
			int d = abs(map[x][y] - map[nx][ny]);
			if (d >= L && d <= R) {
				visited[nx][ny] = ans;
				total += map[nx][ny];
				cnt++;
				dfs(nx, ny);
			}
		}
	}
}
void calArea() {
	if (cnt>1) {
		moved = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j]==ans) {
					map[i][j] = total / cnt;
					visited[i][j] = -2;
				}
			}
		}
	}
}
int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	while (true) {
		memset(visited, -1, sizeof(visited));
		moved = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j]==-1) {
					total = map[i][j];
					cnt = 1;
					visited[i][j] = ans;
					dfs(i, j);
					calArea();
					if (cnt) visited[i][j] = -2;
				}
			}
		}
		if (!moved) break;
		else ans++;
	}
	cout << ans << '\n';
	
	return 0;
}