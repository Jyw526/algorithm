#include <iostream>
#include <algorithm>
using namespace std;
int N;
int A[10001];

int grape() {
	int dp[10001];
	dp[1] = A[1];
	dp[2] = A[1] + A[2];
	dp[3] = max(dp[2], A[1] + A[3]);
	dp[3] = max(dp[3], A[2] + A[3]);
	int ans = -1;
	for (int i = 4; i <= N; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + A[i]);
		dp[i] = max(dp[i], dp[i - 3] + A[i - 1] + A[i]);
		ans = max(ans, dp[i]);
	}
	if (N <= 3) ans = dp[N];
	return ans;
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	cout << grape() << '\n';
	return 0;
}