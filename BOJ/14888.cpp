#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int A[101];
int op[4]; //덧셈 뺄셈 곱셈 나눗셈
int minAns = 987654321;
int maxAns = -987654321;

void putOp(int x, int res) {
	if (x == N-1) {
		if (res < minAns) minAns = res;
		if (res > maxAns) maxAns = res;
		return;
	}
	for (int j = 0; j < 4; j++) {
		if (op[j] != 0) {
			op[j]--;
			int tmp = res;
			switch (j) {
			case 0:
				tmp = tmp + A[x + 1];
				break;
			case 1:
				tmp = tmp - A[x + 1];
				break;
			case 2:
				tmp = tmp * A[x + 1];
				break;
			case 3:
				tmp = tmp / A[x + 1];
				break;
			}
			putOp(x + 1, tmp);
			op[j]++;
		}
	}
	
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	putOp(0, A[0]);
	cout << maxAns << '\n';
	cout << minAns << '\n';
	return 0;
}