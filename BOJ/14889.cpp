#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int N;
int S[21][21];
bool check[21];
int ans = 987654321;
void dfs(int idx, vector<int> team) {
	if (team.size() == N / 2) {
		int sum = 0; int sum2 = 0;
		for (int i = 0; i < team.size(); i++) {
			for (int j = i+1; j < team.size(); j++) {
				sum = sum + S[team[i]][team[j]] + S[team[j]][team[i]];
			}
		}
		vector<int> team2;
		for (int i = 0; i < N; i++) {
			if (!check[i]) team2.push_back(i);
		}
		for (int i = 0; i < team2.size(); i++) {
			for (int j = i + 1; j < team2.size(); j++) {
				sum2 = sum2 + S[team2[i]][team2[j]] + S[team2[j]][team2[i]];
			}
		}
		ans = min(abs(sum - sum2), ans);
		return;
	}
	for (int i = idx; i < N; i++) {
		if (!check[i]) {
			check[i] = true;
			team.push_back(i);
			dfs(i, team);
			check[i] = false;
			team.pop_back();
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
		}
	}
	vector <int>v;
	v.push_back(0);
	check[0] = true;
	dfs(1,v);
	cout << ans << '\n';
	return 0;
}