#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int T;
	int dp[12];
	cin >> T;
	dp[1] = 1; dp[2] = 2; dp[3] = 4;

	for (int i = 4; i < 12; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << dp[n] <<'\n';
	
	}
	return 0;
}