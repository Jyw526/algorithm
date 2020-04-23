#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

char map[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int visited[51][51];
int R, C;
int sx, sy;
int ans = 987654321;
queue<pair<int, pair<int, int> > >w;

bool checkRange(int x, int y) {
	if (x < 0 || x >= R || y<0 || y>C) {
		return false;
	}
	return true;
}

void bfs() {
	queue<pair<int,pair<int, int> > >q;
	q.push(make_pair(0,make_pair(sx, sy)));
	visited[sx][sy] = 1;
	while (!q.empty()) {
		int d = q.front().first;
		int wd = w.front().first;
		if (d == wd) {
			while (true) {
				if (w.empty()) break;
				int wd2 = w.front().first;
				if (wd2 != wd)
					break;
				int wx = w.front().second.first;
				int wy = w.front().second.second;
				w.pop();

				for (int i = 0; i < 4; i++) {
					int nwx = wx + dx[i];
					int nwy = wy + dy[i];
					if (checkRange(nwx, nwy) && map[nwx][nwy] == '.') {
						map[nwx][nwy] = '*';
						w.push(make_pair(wd2+1,make_pair(nwx, nwy)));
					}
				}
			}
		}
		
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (checkRange(nx, ny) && !visited[nx][ny]) {
				visited[nx][ny] = 1;
				if (map[nx][ny] == '.') {
					q.push(make_pair(d + 1, make_pair(nx, ny)));
					sx = nx; sy = ny;
				}
				else if (map[nx][ny] == 'D') {
					ans = min(ans, d + 1);
				}
			}
		}
	}
	
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'S') {
				sx = i; sy = j;
				map[i][j] = '.';
			}
			else if(map[i][j] == '*'){
				w.push(make_pair(0,make_pair(i, j)));
			}
		}
	}
	
	bfs();
	if (ans == 987654321) {
		cout << "KAKTUS" << '\n';
		return 0;
	}
	cout << ans << '\n';
	return 0;
}