#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
int K, V, E;
vector<int> arr[20001];
int node[20001];
//g1이면 1, g2이면 2, 방문하지 않았으면 0

void dfs(int n, int g) {
	node[n] = g;
	
	for (int i = 0; i < arr[n].size(); i++) {
		int nx = arr[n][i];
		if (!node[nx])
			dfs(nx, 3 - g);
	}
}

bool checkAns() {
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			//인접인데 같은 그래프에 있는 경우
			if (node[i] == node[arr[i][j]]) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	cin >> K;
	for (int i = 0; i < K; i++) {
		for (int j = 1; j < 20001; j++) {
			arr[j].clear();
		}
		memset(node, 0, sizeof(node));
		cin >> V >> E;

		for (int j = 0; j < E; j++) {
			int a, b;
			cin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}

		for (int j = 1; j <= V; j++) {
			if (!node[j])
				dfs(j, 1);
		}

		if (checkAns()) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}