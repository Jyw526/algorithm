#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
int ans = 0;
vector<int> v[101];
bool visited[101] = { false };

void dfs(int idx) {
	for (int i = 0; i < v[idx].size(); i++) {
		if (!visited[v[idx][i]]) {
			visited[v[idx][i]] = true;
			ans++;
			dfs(v[idx][i]);
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	visited[1] = true;
	dfs(1);
	cout << ans << '\n';
	return 0;
}