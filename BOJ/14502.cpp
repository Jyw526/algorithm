#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int map[9][9];
int map2[9][9];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans = -1;
vector <pair<int, int> > virus;

bool checkRange(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) {
		return false;
	}
	return true;
}
int virusArea() {
	int vmap[9][9];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			vmap[i][j] = map2[i][j];
		}
	}
	queue <pair<int, int> > q;
	for (int i = 0; i < virus.size(); i++) {
		q.push({ virus[i].first, virus[i].second });
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (vmap[nx][ny] == 0 && checkRange(nx, ny)) {
				vmap[nx][ny] = 2;
				q.push({ nx,ny });
			}
		}
	}
	int area = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (vmap[i][j] == 0)
				area++;
		}
	}
	return area;

}
void wall(int cnt) {
	if (cnt == 3) {
		ans = max(ans, virusArea());
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map2[i][j] == 0) {
				map2[i][j] = 1;
				wall(cnt + 1);
				map2[i][j] = 0;
			}
		}
	}

}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back({ i,j });
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {

				for (int k = 0; k < N; k++) {
					for (int l = 0; l < M; l++) {
						map2[k][l] = map[k][l];
					}
				}

				map2[i][j] = 1;
				wall(1);
				map2[i][j] = 0;

			}
		}
	}

	cout << ans << '\n';
}