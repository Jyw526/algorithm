#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int map[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;

int main() {
	int r, c, d;
	int ans = 0;
	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	//현재 위치 청소
	map[r][c] = 2;
	ans++;
	int curr_x = r;
	int curr_y = c;
	int next_x, next_y;
	int cnt = 0;
	
	while (true) {
		int left;
		if (d == 0)
			left = 3;
		else left = d - 1;
		next_x = curr_x + dx[left];
		next_y = curr_y + dy[left];
		//네 방향 모두 청소가 이미 되어있거나 벽인 경우
		if (cnt == 4) {
			cnt = 0;
			//후진할 좌표
			next_x = curr_x - dx[d];
			next_y = curr_y - dy[d];
			//뒤쪽 방향도 벽인 경우
			if (map[next_x][next_y] == 1) {
				break;
			}

			curr_x = next_x;
			curr_y = next_y;
			continue;

		}
		//청소하지 않은 공간 존재
		if (map[next_x][next_y] == 0) {
			cnt = 0;
			d = left;
			curr_x = next_x;
			curr_y = next_y;
			map[curr_x][curr_y] = 2;
			ans++;
			continue;
		}
		else if(map[next_x][next_y]!=0){
			d = left;
			cnt++;
			continue;
		}
	}
	cout << ans << '\n';
	return 0;
}