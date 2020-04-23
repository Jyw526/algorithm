#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <memory.h>
using namespace std;
int N;
int B[100001];
int diff[100001];
int n[9][2] = { {0,-1}, {0,0}, {0,1}, {1,-1}, {1,0}, {1,1}, {-1,-1},{-1,0},{-1,1} };
int ans = 987654321;
int seq(int n1, int n2, int cnt) {
	int temp[100001];
	copy(B, B + N, temp);
	temp[0] += n1; temp[1] += n2;
	int d = abs(temp[0] - temp[1]);

	for (int i = 2; i < N; i++) {
		if (abs(temp[i] - temp[i - 1])==d) {
			continue;
		}
		else if (abs((temp[i]+1) - temp[i - 1])==d) {
			temp[i]++;
			cnt++;
			continue;
		}
		else if (abs((temp[i]-1) - temp[i - 1])==d) {
			temp[i]--;
			cnt++;
			continue;
		}
		else {
			cnt = -1;
			break;
		}
	}
	return cnt;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	int check = 1;
	for (int i = 0; i < N-1; i++) {
		diff[i] = abs(B[i + 1] - B[i]);
		if (check && i > 0 ) {
			if (diff[i] != diff[i - 1])
				check = 0;
		}
	}

	if (check) {
		cout << "0" << '\n';
		return 0;
	}
	else {
		for (int i = 0; i < 9; i++) {
			int cnt = 0;
			if (n[i][0] != 0) cnt++;
			if (n[i][1] != 0) cnt++;
			int res = seq(n[i][0], n[i][1], cnt);
			if (res == -1) continue;
			else {
				ans = min(ans, res);
			}
		}
	}

	if (ans == 987654321) {
		cout << "-1" << '\n';
	}
	else
		cout << ans << '\n';
	return 0;
}