#include <iostream>
#include <algorithm>
using namespace std;
int N;

int main() {
	cin >> N;
	int dp[101][10];
	dp[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1];
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
			}
		}
	}
	long ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += dp[N][i];
	}

	cout << ans % 1000000000 << '\n';
}