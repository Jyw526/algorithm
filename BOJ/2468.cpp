#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int N;
int map[101][101];
int map2[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visited[101][101];
int ans = -1;
int maxH = -1;

void dfs(int x, int y) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && map2[nx][ny] > 0) {
			visited[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}

int rain(int r) {
	int area = 0;
	memset(visited, false, sizeof(visited));

	//맵 복사, 비가 오는 지역 -1 표시
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map2[i][j] = map[i][j];
			if (map2[i][j] <= r) {
				map2[i][j] = -1;
			}
		}
	}
    
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && map2[i][j] > 0) {
				area++;
				dfs(i, j);
			}
		}
	}
	return area;
}
void solution() {
	for (int i = 0; i < maxH; i++) {
		ans = max(ans, rain(i));
	}
	cout << ans << '\n';
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			maxH = max(maxH, map[i][j]);
		}
	}
	solution();
	return 0;
}
