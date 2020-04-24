#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int V, E, x, y;
struct people {
	int parent;
	vector<int> child;
};
people ps[10001];
bool visited[10001];
int common = -1;
int sub = 1;
void dfs(int idx) {
	if (ps[idx].parent != -1) {
		if (visited[ps[idx].parent]) {
			common = ps[idx].parent;
			return;
		}
		visited[ps[idx].parent] = true;
		dfs(ps[idx].parent);
	}
}
void subTree(int idx) {
	//cout << " * " << idx << '\n';
	for (int i = 0; i < ps[idx].child.size(); i++) {
		sub++;
		subTree(ps[idx].child[i]);
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> V >> E >> x >> y;
		sub = 1;
		common = -1;
		memset(visited, false, sizeof(visited));
		for (int j = 0; j < 10001; j++) {
			ps[j].parent = -1;
			ps[j].child.clear();
		}
		for (int j = 0; j < E; j++) {
			int p, c;
			cin >> p >> c;
			ps[p].child.push_back(c);
			ps[c].parent = p;
		}
		dfs(x); dfs(y);
		subTree(common);
		cout << "#" << t << " " << common << " " << sub << '\n';

		
	}
	return 0;
}