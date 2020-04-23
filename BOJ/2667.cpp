#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int map[26][26];
bool visited[26][26] = {false};
int d[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
vector<int> home;
int ans = 0;
int cnt;

bool checkRange(int x, int y) {


	if (x < 0 || x >= N || y < 0 || y >= N) {
		return false;
	}
	return true;
}
void dfs(int x,int y) {
	visited[x][y] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int nx = x + d[i][0];
		int ny = y + d[i][1];
		if (checkRange(nx,ny) && map[nx][ny] && !visited[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && map[i][j] == 1) {
				ans++;
				cnt = 0;
				dfs(i, j);
				home.push_back(cnt);
			}
		}
	}
	cout << ans << '\n';
	sort(home.begin(), home.end());
	for (int i = 0; i < home.size(); i++) {
		cout << home[i] << '\n';
	}
	return 0;
}