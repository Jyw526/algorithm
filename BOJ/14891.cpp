#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <math.h>
using namespace std;
int wheel[4][8];
int k;
vector<pair<int, int> > rt;
void rotate(int n, int d) {
	int temp[8];
	for (int i = 0; i < 8; i++) {
		temp[i] = wheel[n][i];
	}
	if (d == 1) {
		for (int i = 0; i < 8; i++) {
			wheel[n][i] = temp[(i + 7) % 8];
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			wheel[n][i] = temp[(i + 1) % 8];
		}
	}
}
int solution() {
	for (int i = 0; i < k; i++) {
		vector<pair<int, int> > v;
		queue<pair<int, int> > q;
		bool check[4] = { false };

		q.push({ rt[i].first, rt[i].second });
		check[rt[i].first] = true;
		while (!q.empty()) {
			int n = q.front().first;
			int d = q.front().second;
			v.push_back({ n,d });
			q.pop();
			
			//왼쪽 바퀴
			if (n - 1 >= 0 && !check[n-1]) {
				check[n - 1] = true;
				if (wheel[n][6] != wheel[n - 1][2]) {
					q.push({ n - 1,d * (-1) });
				}
			}
			//오른쪽 바퀴
			if (n + 1 < 4 && !check[n+1]) {
				check[n + 1] = true;
				if (wheel[n][2] != wheel[n + 1][6]) {
					q.push({ n + 1,d * (-1) });
				}
			}
		}
		for (int i = 0; i < v.size(); i++) {
			rotate(v[i].first, v[i].second);
		}
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (wheel[i][0])
			ans += pow(2, i);
	}
	return ans;
}
int main() {
	for (int i = 0; i < 4; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 8; j++) {
			wheel[i][j] = str[j] - '0';
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		rt.push_back({ a-1,b });
	}
	cout << solution() << '\n';
	return 0;
}
