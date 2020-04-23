#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
vector<int> arr[2001];
bool visited[2001] = { false, };
int ans = 0;

void dfs(int n, int cnt) {
	if (cnt == 4) {
		ans = 1;
		return;
	}
	if (ans==1) {
		return;
	}

	for (int i = 0; i < arr[n].size(); i++) {
		int m = arr[n][i];
		if (!visited[m]) {
			visited[m] = true;
			dfs(m, cnt + 1);
			visited[m] = false;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		visited[i] = true;
		dfs(i, 0);
		visited[i] = false;
		if (ans == 1) break;
	}
	cout << ans << '\n';
	return 0;
}