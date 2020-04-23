#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
int map[9][9];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
int total = 0;
int ans = 987654321;
bool checkRange(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) {
		return false;
	}
	return true;
}
struct cam {
	int x, y, n;
};
vector<cam> cams;
//i 방향으로 비출 수 있는 범위 표시 , 동 북 서 남 (0,1,2,3)
void checkArea(int i,int x,int y) {
	int nx, ny;
	while (true) {
		nx = x + dx[i]; ny = y + dy[i];
		if (map[nx][ny] == 6 || !checkRange(nx, ny))
			break;
		if(map[nx][ny] == 0)
			map[nx][ny] = 9;
		x = nx; y = ny;
	}
}
void copyMap(int map[9][9], int map2[9][9]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = map2[i][j];
		}
	}
}
void dfs(int cnt) {
	if (cnt == cams.size()) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0)
					sum++;
			}
		}
		ans = min(ans, sum);
		return;
	}
	int n = cams[cnt].n;
	int x = cams[cnt].x;
	int y = cams[cnt].y;

	int map2[9][9];
	copyMap(map2,map);
	switch (n) {
	case 1:
		for (int i = 0; i < 4; i++) {
			checkArea(i, x, y);
			dfs(cnt + 1);
			copyMap(map, map2);
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++) {
			checkArea(i, x, y);
			checkArea(i + 2, x, y);
			dfs(cnt + 1);
			copyMap(map, map2);
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++) {
			checkArea(i, x, y);
			checkArea((i + 1) % 4, x, y);
			dfs(cnt + 1);
			copyMap(map, map2);
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				checkArea((i + j) % 4, x, y);
			}
			dfs(cnt + 1);
			copyMap(map, map2);
		}
		break;
	case 5:
		for (int i = 0; i < 4; i++) {
			checkArea(i, x, y);
		}
		dfs(cnt + 1);
		copyMap(map, map2);
		break;
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				cams.push_back({ i,j,map[i][j] });
			}
			else if(map[i][j] == 0){
				total++;
			}
		}
	}
	dfs(0);
	cout << ans << '\n';
	return 0;
}