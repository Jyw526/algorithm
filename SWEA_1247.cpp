#include <iostream>
#include <algorithm>
using namespace std;
int N;
int loc[13][2];
bool visited[13];
int ans = 987654321;
void distance(int x1, int y1, int x2, int y2) {

}
void dfs(int x1,int y1, int cnt,int d) {
	if (cnt == N) {
		d += abs(x1 - loc[1][0]) + abs(y1 - loc[1][1]);
		ans = min(ans, d);
		return;
	}
	if (d > ans) {
		return;
	}
	for (int i = 2; i < N+2; i++) {
		if (!visited[i]) {
			visited[i] = true;
			d += abs(x1 - loc[i][0]) + abs(y1 - loc[i][1]);
			dfs(loc[i][0], loc[i][1], cnt + 1, d);
			visited[i] = false;
			d -= abs(x1 - loc[i][0]) + abs(y1 - loc[i][1]);
		}
	}
	
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		ans = 987654321;
		for (int i = 2; i < N+2; i++) {
			visited[i] = false;
		}
		for (int i = 0; i < N + 2; i++) {
			int x, y;
			cin >> x >> y;
			loc[i][0] = x; loc[i][1] = y;
		}
		dfs(loc[0][0], loc[0][1], 0, 0);
		cout << "#" << t << " " << ans << '\n';

	}
	return 0;
}
