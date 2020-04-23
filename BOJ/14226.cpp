#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int S;
bool visited[2002] = { false };
int ans = 987654321;
void emoticon() {
	queue <pair<int, pair<int, int> > >q;
	q.push(make_pair(0,make_pair(1,0)));
	while (!q.empty()) {
		int n = q.front().second.first;
		int cnt = q.front().second.second;
		int clip = q.front().first;
		q.pop();
		if (n == S) {
			ans = min(ans, cnt);
		}
		else if (n <= 2 * S) {
			visited[n] = true;
			if (clip > 0 && clip < S && !visited[n + clip]) {
				q.push(make_pair(clip, make_pair(n + clip, cnt + 1)));
			}
			if (clip != n && n < S) {
				q.push(make_pair(n, make_pair(n, cnt + 1)));
			}
			if (n > 1 && n - 1 < 1001 & !visited[n - 1]) {
				q.push(make_pair(clip, make_pair(n - 1, cnt + 1)));
			}
		}
	}
}
int main() {
	cin >> S;
	emoticon();
	cout << ans << '\n';
	return 0;
}