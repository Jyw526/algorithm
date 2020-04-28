#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
int map[21][21];
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
struct babyShark {
	int x, y;
	int size = 2;
	int eat = 0;
	int s = 0;
};
babyShark shark;
bool visited[21][21] = { false };
void solution() {
	while (true) {
		queue<pair<int, pair<int, int> > > q;
		q.push({ 0, { shark.x, shark.y } });
		bool isEat = false;
		memset(visited, false, sizeof(visited));
		visited[shark.x][shark.y] = true;
		bool canEat[21][21] = { false };
		int min = 987654321;
		while (!q.empty()) {
			int cnt = q.front().first;
			int x = q.front().second.first;
			int y = q.front().second.second;
			q.pop();
			if (cnt > min) break;
			if (map[x][y] > 0 && map[x][y] < shark.size) {
				canEat[x][y] = true;
				min = cnt;
				isEat = true;
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (!visited[nx][ny] && nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if (map[nx][ny] >= 0 && map[nx][ny] <= shark.size) {
						visited[nx][ny] = true;
						q.push({ cnt + 1,{nx,ny} });
					}
				}
			}
		}
		if (!isEat) {
			break;
		}
		bool check = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (canEat[i][j]) {
					shark.eat++;
					if (shark.size == shark.eat) {
						shark.size++;
						shark.eat = 0;
					}
					map[i][j] = 0;
					shark.s += min;
					shark.x = i;
					shark.y = j;
					check = true;
					break;
				}
			}
			if (check) break;
		}
	}
	cout << shark.s << '\n';
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark.x = i;
				shark.y = j;
				map[i][j] = 0;
			}
		}
	}
	solution();
	
	return 0;
}