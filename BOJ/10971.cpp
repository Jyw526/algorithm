#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int W[11][11];
bool visited[11] = { false, };
int ans = 987654321;
void dfs(int start, int n, int sum, int cnt) {
	if (cnt == N && start == n) {
		ans = min(ans, sum);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (W[n][i] == 0) continue;
		else {
			if (!visited[n]) {
				visited[n] = true;
				sum += W[n][i];
				if (sum <= ans)
					dfs(start, i, sum, cnt+1);
				visited[n] = false;
				sum -= W[n][i];
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		dfs(i, i, 0, 0);
	}

	cout << ans << '\n';
	return 0;
}