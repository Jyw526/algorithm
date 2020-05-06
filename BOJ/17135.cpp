#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int N, M, D;
int map[16][16];
int ans = -1;

vector<pair<int, int> > enemy;
bool visited[16];
void game(vector<int> archer){

	int cnt = 0;
	
	int copyMap[16][16];

	memset(copyMap, 0, sizeof(copyMap));
	for (int i = 0; i < archer.size(); i++) {
		copyMap[N][archer[i]] = 2;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copyMap[i][j] = map[i][j];
		}
	}
	

	while (true) {
		vector<pair<int, int> > enemy;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copyMap[i][j])
					enemy.push_back({ i,j });
			}
		}

		if (enemy.size() == 0) {
			break;
		}

		//가장 가까운 적 찾기
		vector<int> attacked;
		for (int i = 0; i < archer.size(); i++) {
			int minDis = 987654321;
			int minE = -1;
			for (int j = 0; j < enemy.size(); j++) {
				int d = abs(N - enemy[j].first) + abs(archer[i] - enemy[j].second);
				if (d <= D) {
					if (d < minDis) {
						minDis = d;
						minE = j;
					}
					else if (d == minDis) {
						if (enemy[j].second < enemy[minE].second) {
							minE = j;
						}
					}
				}
			}
			if(minE!= -1) attacked.push_back(minE);
		}

		//공격하여 제거
		for (int i = 0; i < attacked.size(); i++) {
			int x = enemy[attacked[i]].first;
			int y = enemy[attacked[i]].second;
			if (copyMap[x][y]) {
				copyMap[x][y] = 0;
				cnt++;
			}
		}
		for (int i = enemy.size()-1; i >= 0; i--) {
			bool found = false;
			for (int j = 0; j < attacked.size(); j++) {
				if (i == attacked[j]) {
					found = true;
					break;
				}
			}
			if (!found) {
				copyMap[enemy[i].first][enemy[i].second] = 0;
				enemy[i].first++;
	
				if (enemy[i].first != N) {
					copyMap[enemy[i].first][enemy[i].second] = 1;
				}
			}
		}

	}
	ans = max(ans, cnt);
	
	
}
void select(int idx, int cnt) {

	if (cnt == 3) {
		vector<int> archer;
		for (int i = 0; i < M; i++) {
			if (visited[i]) {
				archer.push_back(i);
			}
		}
		game(archer);
	}
	for (int i = idx; i < M; i++) {
		if (!visited[i]) {
			visited[i] = true;
			select(i, cnt + 1);
			visited[i] = false;
		}
	}
}
int main() {
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
;		}
	}
	memset(visited, false, sizeof(visited));
	select(0, 0);
	cout << ans << '\n';
	return 0;
}
