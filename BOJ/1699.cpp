#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int N;
int dp[100001];

int main() {
	cin >> N;
	
	//제곱수 dp 업데이트
	for (int i = 1; i * i <= N; i++) {
		dp[i*i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		if (dp[i] == 1) continue;
		dp[i] = 987654321;
		for (int j = sqrt(i); j >= 1; j--) {
			dp[i] = min(dp[i], 1 + dp[i - (j * j)]);
		}
	}

	cout << dp[N] << '\n';
	return 0;
}