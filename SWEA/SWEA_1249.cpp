#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, ans;
const int INF = 987654321;
int map[101][101];
int dist[101][101];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push({ x,y });
	dist[x][y] = 0;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if(dist[nx][ny] > dist[x][y] + map[nx][ny]){
					dist[nx][ny] = dist[x][y] + map[nx][ny];
					q.push({ nx,ny });
				}
			}
		}
	}

}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		ans = INF;
		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < N; j++) {
				map[i][j] = str[j] - '0';
				dist[i][j] = INF;
			}
		}
		bfs(0,0);
		cout << "#" << t << " " <<  dist[N-1][N-1] << '\n';
	}
	return 0;
}
