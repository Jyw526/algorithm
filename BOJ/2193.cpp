#include <iostream>
#include <algorithm>
using namespace std;
int N;
long long primaryNum() {
	long long dp[91][2];
	dp[1][0] = 0;
	dp[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i-1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	return dp[N][0] + dp[N][1];
}
int main() {
	cin >> N;
	cout << primaryNum() << '\n';
	return 0;
}