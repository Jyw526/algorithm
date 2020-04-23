#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <memory.h>
using namespace std;

int w, h;
int map[51][51];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool checkRange(int x, int y) {
	if (x < 0 || x >= h || y < 0 || y >= w)
		return false;
	return true;
}
void findIsland(int x, int y) {

	map[x][y] = 2;
	//printmap();
	for (int i = 0; i < 8; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		//범위 체크
		if (checkRange && map[nextX][nextY]==1) {
			findIsland(nextX, nextY);
		}
	}
}
int main() {
	while (true) {
		int ans = 0;
		cin >> w >> h;
		memset(map, 0, sizeof(map));

		if (w == 0 && h == 0) {
			return 0;
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1) {
					ans++;
					findIsland(i,j);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}