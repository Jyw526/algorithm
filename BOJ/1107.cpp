#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
bool broken[10] = { false };
const int MAX = 1000001;

bool check(int n) {
	if (n == 0) {
		if (broken[0])
			return false;
		else return true;
	}
	while (n > 0) {
		int i = n % 10;
		n /= 10;
		if (broken[i]) {
			return false;
		}
	}
	return true;
}

int length(int n) {
	int len = 0;
	if (n == 0) return 1;
	while (n > 0) {
		n /= 10;
		len++;
	}
	return len;
}
int remocon() {
	int cnt = abs(100 - N);
	int idx;
	if (cnt != 0) {
		for (int i = 0; i < MAX; i++) {
			if (check(i)) {
				int d = abs(N - i);
				if (length(i) + d < cnt) {
					cnt = length(i) + d;
				}
			}
		}
	}
	return cnt;

}
int main() {
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		broken[a] = true;
	}


	cout << remocon() << '\n';
	return 0;
}