#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
int map[51][51];
vector <pair<int, int> > home;
vector <pair<int, int> > chicken;
vector <int> selected;
const int MAX = 987654321;
int ans = MAX;
bool visited[14] = { false };
int cal() {
	int total = 0;
	for (int i = 0; i < home.size(); i++) {
		int mindis = MAX;
		int hx = home[i].first;
		int hy = home[i].second;
		for (int j = 0; j < M; j++) {
			int cx = chicken[selected[j]].first;
			int cy = chicken[selected[j]].second;
			int d = abs(hx - cx) + abs(hy - cy);
			mindis = min(mindis, d);
		}
		total += mindis;
	}
	return total;
}
void select(int idx) {
	if (selected.size() == M) {
		ans = min(ans, cal());
		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			selected.push_back(i);
			select(i);
			selected.pop_back();
			visited[i] = false;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				home.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}
	select(0);
	cout << ans << '\n';
	return 0;
}