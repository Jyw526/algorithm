#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <memory.h>
#include <queue>
using namespace std;
int N, M, V;
vector<int> con[1001];
bool visited[1001];
queue<int> q;
void dfs(int v) {
	visited[v] = true;
	cout << v << " ";
	for (int i = 0; i < con[v].size(); i++) {
		int nx = con[v][i];
		if (!visited[nx])
			dfs(nx);
	}
}

void bfs(int v) {

	q.push(v);
	visited[v] = true;
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		cout << n << " ";

		for (int i = 0; i < con[n].size(); i++) {
			int nx = con[n][i];
			if (!visited[nx]) {
				q.push(nx);
				visited[nx] = true;
			}
		}

	}
}
int main() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		con[u].push_back(v);
		con[v].push_back(u);
	}
	for (int i = 0; i < N; i++) {
		sort(con[i].begin(), con[i].end());
	}
	dfs(V);
	cout << "\n";
	memset(visited, false, sizeof(visited));
	bfs(V);
	cout << '\n';

	return 0;
}