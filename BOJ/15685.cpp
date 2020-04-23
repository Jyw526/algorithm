#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int map[100][100] = { 0, };


void dragonCurve(int x, int y, int d, int g) {
	while (g > 0) {

	}
}

int main() {
	int ans = 0;
	int C;
	int dir[1024];
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, 1 };
	cin >> C;
	
	for (int i = 0; i < C; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		dir[0] = d;
		map[x][y] = 1;
		//방향 정보 기입
		for (int i = 1; i <= g; i++) {
			int t = pow(2, i); 
			for (int j = pow(2,i-1); j < t ; j++) {
				dir[j] = (dir[t - 1 - j] + 1) % 4;
			}
		}
		int pre_x = x;
		int pre_y = y;
		int next_x;
		int next_y;

		for (int i = 1; i < pow(2, g) + 1; i++) {
			int d = dir[i - 1];
			next_x = pre_x + dx[d];
			next_y = pre_y + dy[d];
			map[next_x][next_y] = 1;
			pre_x = next_x; 
			pre_y = next_y;
		}

	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
				ans++;
		}
	}

	cout << ans << '\n';
}