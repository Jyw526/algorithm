#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <memory.h>
#include <string>
#include <math.h>
using namespace std;
int map[51][101];
int N, M;
int num[10][7] = {
	{0,0,0,1,1,0,1}, {0,0,1,1,0,0,1},
	{0,0,1,0,0,1,1}, {0,1,1,1,1,0,1},
	{0,1,0,0,0,1,1}, {0,1,1,0,0,0,1},
	{0,1,0,1,1,1,1}, {0,1,1,1,0,1,1},
	{0,1,1,0,1,1,1}, {0,0,0,1,0,1,1}
};
void pw() {
	int x, y;
	bool find = false;
	int code[8];
	for (int i = M; i > 0; i--) {
		for (int j = 0; j < N; j++) {
			if (map[j][i] == 1) {
				x = j; y = i;
				find = true;
				break;
			}
		}
		if (find) break;
	}
	int idx = 0;
	for (int j = y - 55; j <= y - 6; j += 7) {
		for (int m = 0; m < 10; m++) {
			bool c = true;
			for (int k = 0; k < 7; k++) {
				if (map[x][j + k] != num[m][k]) {
					c = false;
					break;
				}
			}
			if (c) {
				code[idx] = m;
				break;
			}
		}
		idx++;
	}
	int oddSum = 0;
	int evenSum = 0;
	for (int i = 0; i < 7; i++) {
		if (i % 2 == 1) {
			evenSum += code[i];
		}
		else {
			oddSum += code[i];
		}
	}
	if (((oddSum * 3) + evenSum + code[7]) % 10 == 0){
		int sum = 0;
		for (int i = 0; i < 8; i++) {
			sum += code[i];
		}
		cout << sum << '\n';
	}
	else {
		cout << "0" << '\n';
	}

}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < M; j++) {
				map[i][j] = str[j] - '0';
			}
		}
		cout << "#" << t << " ";
		pw();
	}
	return 0;
}