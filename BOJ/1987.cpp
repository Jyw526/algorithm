#include <iostream>
#include <algorithm>
using namespace std;
int R, C;
char board[21][21];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visited[26] = { false };
int ans = 1;
void dfs(int x, int y, int cnt) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[board[nx][ny]-'A']) {
			visited[board[nx][ny]-'A'] = true;
			dfs(nx, ny, cnt+1);
			visited[board[nx][ny] - 'A'] = false;
			
		}
	}

	ans = max(ans, cnt);
}
int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			board[i][j] = str[j];
		}
	}
	vector<char> v;
	v.push_back(board[0][0]);
	visited[board[0][0]-'A'] = true;
	dfs(0,0, 1);
	cout << ans << '\n';
	return 0;
}
​
