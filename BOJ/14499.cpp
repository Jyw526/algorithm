#include <iostream>
#include <algorithm>
using namespace std;
int N, M, x, y, k;
int map[21][21];
int order[1001];
int dice[6] = { 0,0,0,0,0,0 };
int after[4][6] = { {0,5,1,2,4,3},{0,2,3,5,4,1},{2,1,4,3,5,0},{5,1,0,3,2,4} };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
//윗면 dice[2], 아랫면 dice[5]

void rolling(int n) {
	int temp[6];
	for (int i = 0; i < 6; i++)
		temp[i] = dice[i];
	for (int i = 0; i < 6; i++) {
		dice[i] = temp[after[n - 1][i]];
	}
}
void move() {
	for (int i = 0; i < k; i++) {
		int d = order[i];
		int nx = x + dx[d - 1];
		int ny = y + dy[d - 1];
;		if (nx >= 0 && nx < N && ny>=0 && ny < M) {
			rolling(d);
			cout << dice[2] << '\n';
			if (map[nx][ny] == 0) {
				map[nx][ny] = dice[5];
			}
			else {
				dice[5] = map[nx][ny];
				map[nx][ny] = 0;
			}
			x = nx;
			y = ny;
		}
	}
}
int main() {
	cin >> N >> M >> x >> y >> k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> order[i];
	}
	move();
	return 0;
}