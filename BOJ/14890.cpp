#include <iostream>
#include <algorithm>
using namespace std;
int N, L;
int map[101][191];

int slope() {
	int ans = 0;
	//가로 길 검사
	for (int i = 0; i < N; i++) {
		int h = map[i][0];
		bool check = true;
		bool down = false;
		int len = 1;
		for (int j = 1; j < N; j++) {

			if (map[i][j] == h) {
				len++;
				if (down && len == L) {
					down = false;
					len = 0;
				}
			}
			else if (map[i][j] == h + 1) {
				if (down) {
					check = false;
					break;
				}
				if (len >= L) {
					len = 1;
				}
				else {
					check = false;
					break;
				}
			}
			else if (map[i][j] == h - 1) {
				if (L == 1) {
					len = 0;
				}
				else {
					if (!down) {
						down = true;
						len = 1;
					}
					else {
						check = false;
						break;
					}
				}

			}
			else {
				check = false;
				break;
			}

			if (j == N - 1) {

				if (down && len < L) {
					check = false;
					break;
				}
			}
			h = map[i][j];
		}
		if (check) 
			ans++;
	}
	 

	//세로 길 검사
	for (int j = 0; j < N; j++) {
		int h = map[0][j];
		bool check = true;
		bool down = false;
		int len = 1;
		for (int i = 1; i < N; i++) {
			if (map[i][j] == h) {
				len++;
				if (down && len == L) {
					down = false;
					len = 0;
				}
			}
			else if (map[i][j] == h + 1) {
				if (down) {
					check = false;
					break;
				}
				if (len >= L) {
					len = 1;
				}
				else {
					check = false;
					break;
				}
			}
			else if (map[i][j] == h - 1) {
				if (L == 1) {
					len = 0;
				}
				else {
					if (!down) {
						down = true;
						len = 1;
					}
					else {
						check = false;
						break;
					}
				}

			}
			else {
				check = false;
				break;
			}
			h = map[i][j];
			if (i == N - 1) {
				if (down && len < L) {
					check = false;
				}
			}
		}
		if (check)
			ans++;
	}
	return ans;
}
int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	cout << slope() << '\n';
	

	return 0;
}