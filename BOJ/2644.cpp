#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, x, y, M;
vector <pair<int, int> > r;
int ans = -1;
struct people {
	int parent = -1;
	vector <int> child;
};
people ps[101];
bool visited[101] = { false };
void dfs(int idx, int cnt) {
	if (idx == y) {
		ans = cnt;
		return;
	}
	if (ps[idx].parent != -1 && !visited[ps[idx].parent]) {
		visited[ps[idx].parent] = true;
		dfs(ps[idx].parent, cnt + 1);
	}
	for (int i = 0; i < ps[idx].child.size(); i++) {
		if (!visited[ps[idx].child[i]]) {
			visited[ps[idx].child[i]] = true;
			dfs(ps[idx].child[i], cnt + 1);
		}
		
	}
}
int main() {
	cin >> N >> x >> y >> M;
	for (int i = 0; i < M; i++) {
		int p, c;
		cin >> p >> c;
		ps[p].child.push_back(c);
		ps[c].parent = p;
	}
	visited[x] = true;
	dfs(x, 0);
	cout << ans << '\n';

	return 0;
}