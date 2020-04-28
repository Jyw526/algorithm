#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int F, S, G, U, D;
const int MAX = 1000001;
bool visited[MAX];
int bfs() {
	//현재 위치, cnt
	queue<pair<int,int>> q;
	q.push({ S,0 });
	visited[S] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur == G) {
			return cnt;
		}
		if (cur + U <= F && !visited[cur + U]) {
			visited[cur + U] = true;
			q.push({ cur + U,cnt + 1 });
		}
		if (cur - D >= 1 && !visited[cur - D]) {
			visited[cur - D] = true;
			q.push({ cur - D,cnt + 1 });
		}
	}
	return -1;
}
int main() {
	cin >> F >> S >> G >> U >> D;
	int ans = bfs();
	if (ans == -1) {
		cout << "use the stairs" << '\n';
	}
	else {
		cout << ans << '\n';
	}
	return 0;
}