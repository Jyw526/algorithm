#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100001;
int N, K;
bool visited[MAX];

int bfs() {
	queue<pair<int, int> > q;
	q.push(make_pair(N, 0));
	visited[N] = true;

	while (!q.empty()) {
		int n = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (n == K) {
			return cnt;
		}

		if (n + 1 < MAX && !visited[n + 1]) {
			visited[n + 1] = true;
			q.push(make_pair(n + 1, cnt + 1));
		}
		if (n - 1 >= 0 && !visited[n - 1]) {
			visited[n - 1] = true;
			q.push(make_pair(n - 1, cnt + 1));
		}
		if (n * 2 < MAX && !visited[n * 2]) {
			visited[n * 2] = true;
			q.push(make_pair(n * 2, cnt + 1));
		}
	}
}
int main() {
	cin >> N >> K;
	cout << bfs() << '\n';
	return 0;
}