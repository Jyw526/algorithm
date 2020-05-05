#include <iostream>
#include <algorithm>
using namespace std;
int N, K;
int coin[101];
int dp[10001] = { 0, };
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}
	dp[0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = coin[i]; j <= K; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[K] << '\n';
	return 0;
}
