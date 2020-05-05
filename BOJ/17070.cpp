#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int map[17][17];
int ans = 0;
struct pipe {
	int x1, y1, x2, y2;
};
bool checkRange(int x,int y, bool diag) {
	if (!map[x][y]) {
		if (diag) {
			if (map[x - 1][y] || map[x][y - 1])
				return false;
		}
		if (x > 0 && x <= N && y > 0 && y <= N) {
			return true;
		}
	}
	return false;
}
vector<pair<int, pair<int, int> > > d[3] = 
{ {{0,{0,1}},{2,{1,1}}}, {{1,{1,0}},{2,{1,1}}}, {{0,{0,1}},{1,{1,0}},{2,{1,1}}} }; //가로, 세로, 대각선
void dfs(pipe p, int dir) {
	if (p.x2 == N && p.y2 == N) {
		ans++;
	}
	for (int i = 0; i < d[dir].size(); i++) {
		int d2 = d[dir][i].first;
		bool diag = false;
		if (d2 == 2) diag = true; //대각선 방향 회전인가?
		int nx2 = p.x2 + d[dir][i].second.first;
		int ny2 = p.y2 + d[dir][i].second.second;
		if (checkRange(nx2, ny2, diag)) {
			pipe newP;
			newP.x1 = p.x2; newP.y1 = p.y2;
			newP.x2 = nx2; newP.y2 = ny2;
			dfs(newP, d2);
		}

	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	pipe p = { 1,1,1,2 };
	dfs(p, 0);
	cout << ans << '\n';
	return 0;
}
