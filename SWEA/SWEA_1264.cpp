#include <iostream>
#include <algorithm>
using namespace std;
int N;
int ans = 0;
string X, Y;
int lcs[501][501];
void solution() {
	X = "0" + X;
	Y = "0" + Y;
	N++;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == 0 || j == 0) {
				lcs[i][j] = 0;
				continue;
			}
			if (X[i] == Y[j]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}
	float ans = ( lcs[N - 1][N - 1] / (float)(N-1) ) * 100;
	
	cout << fixed;
	cout.precision(2);
	cout << ans << '\n';
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		cin >> X >> Y;
		cout << "#" << t << " ";
		solution();
	}
	
	return 0;
}
