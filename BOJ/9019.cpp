#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <memory.h>
#include <string>
using namespace std;
int A, B;

void bfs() {
	bool visited[10001] = { false };
	queue <pair <int, string> > q;
	q.push(make_pair(A,""));
	while (!q.empty()) {
		int n = q.front().first;
		string str = q.front().second;
		q.pop();
		
		if (n == B) {
			cout << str << '\n';
			return;
		}

		//D
		int d = (2 * n) % 10000;
		if(!visited[d]) q.push(make_pair(d, str + "D"));
		visited[d] = true;

		//S
		int s;
		if (n == 0) {
			s = 9999;
		}
		else {
			s = n - 1;
		}
		if(!visited[s]) q.push(make_pair(s, str + "S"));
		visited[s] = true;

		//L
		int l = (n % 1000) * 10 + n / 1000;
		if(!visited[l]) q.push(make_pair(l, str + "L"));
		visited[l] = true;

		//R
		int r = (n % 10) * 1000 + (n / 10);
		if(!visited[r]) q.push(make_pair(r, str + "R"));
		visited[r] = true;
	}
}
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		bfs();
	}

	return 0;
}