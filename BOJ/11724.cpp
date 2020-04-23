#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
vector<int> graph[1001];
bool visited[1001];
int ans = 0;

void dfs(int n) {
	visited[n] = true;
	for (int i = 0; i < graph[n].size(); i++) {
		int n2 = graph[n][i];
		if (!visited[n2])
			dfs(n2);
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}