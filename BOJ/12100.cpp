#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include<memory.h>

using namespace std;

int N;
int ans = -2;
bool visited[21][21];


void move(int board[][21], int d) {

	//->방향
	if (d == 0) {
		for (int j = N - 2; j >= 0; j--) {
			for (int i = 0; i < N; i++) {
				if (board[i][j] > 0) {
					for (int s = j + 1; s < N; s++) {
						if (board[i][s-1] == board[i][s] && !visited[i][s]) {
							board[i][s] = 2 * board[i][s];
							board[i][s-1] = 0;
							visited[i][s] = true;
							break;
						}
						else if(board[i][s] == 0){
							board[i][s] = board[i][s-1];
							board[i][s-1] = 0;
							continue;
						}
						else {
							break;
						}
					}
				}
			}
		}
	}

	// v 아래방향
	else if (d == 1) {
		for (int i = N - 2; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] > 0) {
					for (int s = i + 1; s < N; s++) {
						if (board[s-1][j] == board[s][j] && !visited[s][j]) {
							board[s][j] = 2 * board[s][j];
							board[s-1][j] = 0;
							visited[s][j] = true;
							break;
						}
						else if (board[s][j] == 0) {
							board[s][j] = board[s-1][j];
							board[s-1][j] = 0;
							continue;
						}
						else {
							break;
						}
					}
				}
			}
		}
	}

	// <- 방향
	else if (d == 2) {
		for (int j = 1; j < N; j++) {
			for (int i = 0; i < N; i++) {
				if (board[i][j] > 0) {
					for (int s = j - 1; s >= 0; s--) {
						if (board[i][s + 1] == board[i][s] && !visited[i][s]) {
							board[i][s] = 2 * board[i][s];
							board[i][s + 1] = 0;
							visited[i][s] = true;
							break;
						}
						else if (board[i][s] == 0) {
							board[i][s] = board[i][s + 1];
							board[i][s + 1] = 0;
							continue;
						}
						else {
							break;
						}
					}
				}
			}
		}
	}

	// ^위방향
	else {
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] > 0) {
					for (int s = i - 1; s >=0; s--) {
						if (board[s + 1][j] == board[s][j] && !visited[s][j]) {
							board[s][j] = 2 * board[s][j];
							board[s + 1][j] = 0;
							visited[s][j] = true;
							break;
						}
						else if (board[s][j] == 0) {
							board[s][j] = board[s + 1][j];
							board[s + 1][j] = 0;
							continue;
						}
						else {
							break;
						}
					}
				}
			}
		}
	}
}

int findMax(int board[][21]) {
	int n = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			n = max(n, board[i][j]);
		}
	}
	return n;
}
void game(int cnt,int maxNum, int board[][21], vector<int> v ) {
	if (cnt == 5) {
		if (maxNum > ans) {
			ans = maxNum;

		}
		return;

	}
	
	for (int i = 0; i < 4; i++) {
		int board2[21][21];
		for (int m = 0; m < N; m++) {
			for (int n = 0; n < N; n++) {
				board2[m][n] = board[m][n];
			}
		}
		memset(visited, false, sizeof(visited));
		move(board2, i);
		v.push_back(i);
		game(cnt + 1, findMax(board2), board2, v);
		v.pop_back();
	}

}
int main() {
	int board[21][21];
	vector <int> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	game(0, -1, board, v);
	cout << ans << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << '\n';

	return 0;
}