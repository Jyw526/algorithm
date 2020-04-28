#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M;
const int MAX = 987654321;
char map[11][11];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
int ans = MAX;
bool visited[11][11][11][11] = { false };
struct red {
	int x, y;
};
struct blue {
	int x, y;
};
struct red r; struct blue b;
bool checkRange(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < M && map[x][y]!='#')
		return true;
	return false;
}
void bfs() {
	queue < pair< int, pair<struct red, struct blue> > >q;
	q.push({ 0, {r,b} });
	visited[r.x][r.y][b.x][b.y] = true;
	while (!q.empty()) {
		int cnt = q.front().first;
		struct red r = q.front().second.first; struct blue b = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int rx = r.x; int ry = r.y; int bx = b.x; int by = b.y;
			bool moved = false;
			bool rgoal = false;  bool bgoal = false;
			while (true) {
				bool rflag = true; bool bflag = true;
				int nrx = rx + dx[i]; int nry = ry + dy[i];
				int nbx = bx + dx[i]; int nby = by + dy[i];
				if (checkRange(nrx, nry) && !(nrx == bx && nry == by) && !rgoal) {
					moved = true;
					if (map[nrx][nry] == '.') {
						rx = nrx; ry = nry;
						rflag = true;
					}
					else if (map[nrx][nry] == 'O') {
						rgoal = true;
						rx = -1; ry = -1;
						rflag = false;
						//ans = min(ans, cnt + 1);
					}
				}
				else {
					rflag = false;
				}
				if (checkRange(nbx, nby) && !(nbx == rx && nby == ry) && !bgoal) {
					moved = true;
					if (map[nbx][nby] == '.') {
						
						bx = nbx; by = nby;
						bflag = true;
					}
					else if (map[nbx][nby] == 'O') {
						bx = -1; by = -1;
						bgoal = true;
						bflag = false;
					}
				}
				else {
					bflag = false;
				}
				if (!rflag && !bflag) {
					break;
				}
			}

			if (moved) {
				if (rgoal && !bgoal) {
					ans = min(ans, cnt + 1);
				}
				else if(!bgoal){
					if (!visited[rx][ry][bx][by] && cnt+1 <= 9) {
						struct red newR = { rx,ry };
						struct blue newB = { bx,by };
						q.push({ cnt + 1,{newR,newB} });
						visited[rx][ry][bx][by] = true;
					}
				}
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'R') {
				r.x = i; r.y = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				b.x = i; b.y = j;
				map[i][j] = '.';
			}
		}
	}
	bfs();
	if (ans == MAX) {
		cout << "-1" << '\n';
	}
	else {
		cout << ans << '\n';
	}
	return 0;
}