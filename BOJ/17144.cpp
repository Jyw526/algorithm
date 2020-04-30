#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int R, C, T;
int map[51][51];
vector <int> machine;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void printmap() {
	cout << '\n';
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}
}
bool checkRange(int x, int y) {
	if (x >= 0 && x < R && y >= 0 && y < C && map[x][y] >= 0) {
		return true;
	}
	return false;
}
void solution() {
	int m1 = machine[0];
	int m2 = machine[1];
	while (T > 0) {
		T--;
		vector<pair<pair<int, int>, int > >dirt;
		//먼지 위치 저장
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] > 0) {
					dirt.push_back({ { i,j },map[i][j] });
					map[i][j] = 0;
				}
			}
		}
		//먼지 확산
		for (int i = 0; i < dirt.size(); i++) {
			int m = dirt[i].second / 5;
			int cnt = 0;
			for (int j = 0; j < 4; j++) {
				int nx = dirt[i].first.first + dx[j];
				int ny = dirt[i].first.second + dy[j];
				if (checkRange(nx, ny)) {
					map[nx][ny] += m;
					cnt++;
				}
			}
			map[dirt[i].first.first][dirt[i].first.second] += dirt[i].second - (cnt * m);
		}
		int temp[51][51];
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				temp[i][j] = map[i][j];
			}
		}
		//공기청정기
		//위쪽 반시계방향
		map[m1][1] = 0;
		for (int i = 2; i < C; i++) {
			map[m1][i] = temp[m1][i - 1];
		}
		for (int i = m1 - 1; i >= 0; i--) {
			map[i][C - 1] = temp[i + 1][C - 1];
		}
		for (int i = C - 2; i >= 0; i--) {
			map[0][i] = temp[0][i + 1];
		}
		for (int i = 1; i < m1; i++) {
			map[i][0] = temp[i - 1][0];
		}
		//아래쪽 시계방향
		map[m2][1] = 0;
		for (int i = 2; i < C; i++) {
			map[m2][i] = temp[m2][i - 1];
		}
		for (int i = m2 + 1; i < R; i++) {
			map[i][C - 1] = temp[i - 1][C - 1];
		}
		for (int i = C - 2; i >= 0; i--) {
			map[R - 1][i] = temp[R - 1][i + 1];
		}
		for (int i = R - 2; i > m2; i--) {
			map[i][0] = temp[i + 1][0];
		}
		
	}
	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) {
				ans += map[i][j];
			}
		}
	}
	cout << ans << '\n';
}
int main() {
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				machine.push_back(i);
			}
		}
	}
	solution();
	return 0;
}